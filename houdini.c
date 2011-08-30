#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"
#include "html_unescape.h"

static const char HTML_ESCAPE_TABLE[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 4, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 6, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const char *HTML_ESCAPES[] = {
        "",
        "&quot;",
        "&amp;",
        "&#39;",
        "&#47;",
        "&lt;",
        "&gt;"
};

static signed char HEX_DIGITS[] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 00 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 10 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 20 */
	 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1, /* 30 */
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 40 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 50 */
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 60 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 70 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 80 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 90 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* a0 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* b0 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* c0 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* d0 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* e0 */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* f0 */
};

void
houdini_escape_html(struct buf *ob, const char *src, size_t size)
{
	size_t  i = 0, org, esc;

	while (i < size) {
		org = i;
		while (i < size &&
			(esc = HTML_ESCAPE_TABLE[src[i] & 0x7F]) == 0 &&
			(src[i] & ~0x7F) == 0)
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		bufputs(ob, HTML_ESCAPES[esc]);
		i++;
	}
}

static void
bufput_utf8(struct buf *ob, int c)
{
	if (c < 0x80) {
		bufputc(ob, c);
	}

	else if (c < 0x800) {
		bufputc(ob, 192 + (c / 64));
		bufputc(ob, 128 + (c % 64));
	}
	
	else if (c - 0xd800u < 0x800) {
		bufputc(ob, '?');
	}

	else if (c < 0x10000) {
		bufputc(ob, 224 + (c / 4096));
		bufputc(ob, 128 + (c / 64) % 64);
		bufputc(ob, 128 + (c % 64));
	}

	else if (c < 0x110000) {
		bufputc(ob, 240 + (c / 262144));
		bufputc(ob, 128 + (c / 4096) % 64);
		bufputc(ob, 128 + (c / 64) % 64);
		bufputc(ob, 128 + (c % 64));
	}

	else {
		bufputc(ob, '?');
	}
}

static inline size_t
unescape_ent(struct buf *ob, const char *src, size_t size)
{
	size_t i = 0;

	if (size > 3 && src[0] == '#') {
		int codepoint = 0;

		i = i + 1;
		
		if (isdigit(src[1])) {
			do {
				codepoint = (codepoint * 10) + (src[i] - '0');
				i++;
			} while (i < size && isdigit(src[i]));
		}

		else if (src[1] == 'x' || src[1] == 'X') {
			i = i + 1; /* skip x prefix */

			while (i < size) {
				int digit = HEX_DIGITS[src[i]];
				if (digit < 0)
					break;

				codepoint = (codepoint * 16) + digit;
				i++;
			}
		}

		if (i < size && src[i] == ';') {
			bufput_utf8(ob, codepoint);
			return i + 1;
		}
	}

	else {
		if (size > MAX_WORD_LENGTH)
			size = MAX_WORD_LENGTH;

		for (i = MIN_WORD_LENGTH; i < size; ++i) {
			if (src[i] == ' ')
				break;

			if (src[i] == ';') {
				const struct html_ent *entity = 
					find_entity(src, i);

				if (entity != NULL) {
					bufput(ob, entity->utf8, entity->utf8_len);
					return i + 1;
				}

				break;
			}
		}
	}

	bufputc(ob, '&');
	return 0;
}

void
houdini_unescape_html(struct buf *ob, const char *src, size_t size)
{
	size_t  i = 0, org;

	while (i < size) {
		org = i;
		while (i < size && src[i] != '&')
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		i++;
		i += unescape_ent(ob, src + i, size - i);
	}
}

#ifdef TEST

int main()
{
	const char TEST_STRING[] = "This &#x2663; is & just &quot;an example&diams;&quot;";
	struct buf *buffer;

	buffer = bufnew(128);
	houdini_unescape_html(buffer, TEST_STRING, strlen(TEST_STRING));
	printf("Result: %.*s\n", (int)buffer->size, buffer->data);
	bufrelease(buffer);
	return 0;
}
#endif

