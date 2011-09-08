#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"
#include "html_unescape.h"

#define UNESCAPE_GROW_FACTOR(x) (x) /* unescaping shouldn't grow our buffer */

static inline void
bufput_utf8(struct buf *ob, int c)
{
	unsigned char unichar[4];

	if (c < 0x80) {
		bufputc(ob, c);
	}
	else if (c < 0x800) {
		unichar[0] = 192 + (c / 64);
		unichar[1] = 128 + (c % 64);
		bufput(ob, unichar, 2);
	}
	else if (c - 0xd800u < 0x800) {
		bufputc(ob, '?');
	}
	else if (c < 0x10000) {
		unichar[0] = 224 + (c / 4096);
		unichar[1] = 128 + (c / 64) % 64;
		unichar[2] = 128 + (c % 64);
		bufput(ob, unichar, 3);
	}
	else if (c < 0x110000) {
		unichar[0] = 240 + (c / 262144);
		unichar[1] = 128 + (c / 4096) % 64;
		unichar[2] = 128 + (c / 64) % 64;
		unichar[3] = 128 + (c % 64);
		bufput(ob, unichar, 4);
	}
	else {
		bufputc(ob, '?');
	}
}

static size_t
unescape_ent(struct buf *ob, const uint8_t *src, size_t size)
{
	size_t i = 0;

	if (size > 3 && src[0] == '#') {
		int codepoint = 0;

		if (_isdigit(src[1])) {
			for (i = 1; i < size && _isdigit(src[i]); ++i)
				codepoint = (codepoint * 10) + (src[i] - '0');
		}

		else if (src[1] == 'x' || src[1] == 'X') {
			for (i = 2; i < size && _isxdigit(src[i]); ++i)
				codepoint = (codepoint * 16) + ((src[i] | 32) % 39 - 9);
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
				const struct html_ent *entity = find_entity((char *)src, i);

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
houdini_unescape_html(struct buf *ob, const uint8_t *src, size_t size)
{
	size_t  i = 0, org;

	bufgrow(ob, UNESCAPE_GROW_FACTOR(size));

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

