#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"

#define UNESCAPE_GROW_FACTOR(x) (x)
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
houdini_unescape_uri(struct buf *ob, const uint8_t *src, size_t size)
{
	return unescape(ob, src, size, 0);
}

void
houdini_unescape_url(struct buf *ob, const uint8_t *src, size_t size)
{
	return unescape(ob, src, size, 1);
}

