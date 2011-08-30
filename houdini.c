#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"
#include "html_escape.h"

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

static inline size_t
unescape_ent(struct buf *ob, const char *src, size_t size)
{
	size_t ent;

	if (size > 8)
		size = 8; /* MAX_WORD_LENGTH */

	for (ent = 0; ent < size; ++ent) {
		const struct html_ent *entity;

		if (src[ent] == ' ')
			break;

		if (src[ent] == ';') {
			entity = find_entity(src, ent);

			if (entity != NULL) {
				bufput(ob, entity->utf8, entity->utf8_len);
				return ent + 1;
			}

			break;
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

#define TEST
#ifdef TEST

int main()
{
	const char TEST_STRING[] = "This is & just &quot;an example&diams;&quot;";
	struct buf *buffer;

	buffer = bufnew(128);
	houdini_unescape_html(buffer, TEST_STRING, strlen(TEST_STRING));
	printf("Result: %.*s\n", (int)buffer->size, buffer->data);
	bufrelease(buffer);
	return 0;
}
#endif

