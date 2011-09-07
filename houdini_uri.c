#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"
#include "uri_escape.h"

#define ESCAPE_GROW_FACTOR(x) (((x) * 12) / 10)
#define UNESCAPE_GROW_FACTOR(x) (x)

extern int _isxdigit(int c);

static void
escape(struct buf *ob, const uint8_t *src, size_t size, int is_url)
{
	static const char hex_chars[] = "0123456789ABCDEF";
	const char *safe_table = is_url ? URL_SAFE : URI_SAFE;

	size_t  i = 0, org;
	char hex_str[3];

	bufgrow(ob, ESCAPE_GROW_FACTOR(size));
	hex_str[0] = '%';

	while (i < size) {
		org = i;
		while (i < size && safe_table[src[i]] != 0)
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		if (src[i] == ' ' && is_url) {
			bufputc(ob, '+');
		} else {
			hex_str[1] = hex_chars[(src[i] >> 4) & 0xF];
			hex_str[2] = hex_chars[src[i] & 0xF];
			bufput(ob, hex_str, 3);
		}

		i++;
	}
}

#define hex2c(c) ((c | 32) % 39 - 9)

static void
unescape(struct buf *ob, const uint8_t *src, size_t size, int is_url)
{
	size_t  i = 0, org;

	bufgrow(ob, UNESCAPE_GROW_FACTOR(size));

	while (i < size) {
		org = i;
		while (i < size && src[i] != '%')
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		i++;

		if (i + 1 < size && _isxdigit(src[i]) && _isxdigit(src[i + 1])) {
			unsigned char new_char = (hex2c(src[i]) << 4) + hex2c(src[i + 1]);
			bufputc(ob, new_char);
			i += 2;
		} else {
			bufputc(ob, '%');
		}
	}

	if (is_url) {
		char *find = (char *)bufcstr(ob);
		while ((find = strchr(find, '+')) != NULL)
			*find = ' ';
	}
}


void
houdini_escape_uri(struct buf *ob, const uint8_t *src, size_t size)
{
	return escape(ob, src, size, 0);
}

void
houdini_escape_url(struct buf *ob, const uint8_t *src, size_t size)
{
	return escape(ob, src, size, 1);
}

void
houdini_unescape_uri(struct buf *ob, const uint8_t *src, size_t size)
{
	return unescape(ob, src, size, 0);
}

void
houdini_unescape_url(struct buf *ob, const uint8_t *src, size_t size)
{
	return unescape(ob, src, size, 1);
}



//#define TEST
#ifdef TEST

int main()
{
	const char TEST_STRING[] = "http% this \200 is a test";
	struct buf *buffer;

	buffer = bufnew(128);
	houdini_escape_uri(buffer, TEST_STRING, strlen(TEST_STRING));
	printf("Result: %.*s\n", (int)buffer->size, buffer->data);
	bufrelease(buffer);
	return 0;
}
#endif

