#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"

#define ESCAPE_GROW_FACTOR(x) (((x) * 12) / 10)

static const char JS_ESCAPE[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void
houdini_escape_js(struct buf *ob, const uint8_t *src, size_t size)
{
	size_t  i = 0, org, ch;

	bufgrow(ob, ESCAPE_GROW_FACTOR(size));

	while (i < size) {
		org = i;
		while (i < size && JS_ESCAPE[src[i]] == 0)
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		ch = src[i];
		
		switch (ch) {
		case '/':
			/*
			 * Escape only if preceded by a lt
			 */
			if (i && src[i - 1] == '<')
				bufputc(ob, '\\');

			bufputc(ob, ch);
			break;

		case '\r':
			/*
			 * Escape as \n, and skip the next \n if it's there
			 */
			if (i + 1 < size && src[i + 1] == '\n') i++;

		case '\n':
			/*
			 * Escape actually as '\','n', not as '\', '\n'
			 */
			ch = 'n';

		default:
			/*
			 * Normal escaping
			 */
			bufputc(ob, '\\');
			bufputc(ob, ch);
			break;
		}

		i++;
	}
}

