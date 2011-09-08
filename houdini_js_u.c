#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"

#define UNESCAPE_GROW_FACTOR(x) (x)

void
houdini_unescape_js(struct buf *ob, const uint8_t *src, size_t size)
{
	size_t  i = 0, org, ch;

	bufgrow(ob, UNESCAPE_GROW_FACTOR(size));

	while (i < size) {
		org = i;
		while (i < size && src[i] != '\\')
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i == size)
			break;

		if (++i == size) {
			bufputc(ob, '\\');
			break;
		}

		ch = src[i];

		switch (ch) {
		case 'n':
			ch = '\n';
			/* pass through */

		case '\\':
		case '\'':
		case '\"':
		case '/':
			bufputc(ob, ch);
			i++;
			break;

		default:
			bufputc(ob, '\\');
			break;
		}
	}
}

