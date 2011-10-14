#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "houdini.h"

#define ESCAPE_GROW_FACTOR(x) (((x) * 12) / 10) /* this is very scientific, yes */

/**
 * According to the OWASP rules:
 *
 * & --> &amp;
 * < --> &lt;
 * > --> &gt;
 * " --> &quot;
 * ' --> &#x27;     &apos; is not recommended
 * / --> &#x2F;     forward slash is included as it helps end an XML entity
 *
 */
static const char *LOOKUP_CODES[] = {
	"", /* reserved: use literal single character */
	"", /* reserved */
	"", /* reserved: 2 character UTF-8 */
	"", /* reserved: 3 character UTF-8 */
	"", /* reserved: 4 character UTF-8 */
	"", /* reserved: 5 character UTF-8 */
	"", /* reserved: 6 character UTF-8 */
	"?",
	"&quot;",
	"&amp;",
	"&#39;",
	"&#47;",
	"&lt;",
	"&gt;"
};

static const char XML_LOOKUP_TABLE[] = {
	/* ASCII: 0xxxxxxx */
	7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	0, 0, 8, 0, 0, 0, 9, 10,0, 0, 0, 0, 0, 0, 0,11,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 0,13, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	/* Invalid UTF-8: 10xxxxxx */
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,

	/* Multibyte UTF-8 */

	/* 2 bytes: 110xxxxx */
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

	/* 3 bytes: 1110xxxx */
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,

	/* 4 bytes: 11110xxx */
	4, 4, 4, 4, 4, 4, 4, 4,

	/* 5 bytes: 111110xx */
	5, 5, 5, 5,

	/* 6 bytes: 1111110x */
	6, 6,

	/* Invalid UTF-8: 1111111x */
	7, 7,
};

void
houdini_escape_xml(struct buf *ob, const uint8_t *src, size_t size)
{
	size_t  i = 0, org, code;

	bufgrow(ob, ESCAPE_GROW_FACTOR(size));

	while (i < size) {
		org = i;
		while (i < size && (code = XML_LOOKUP_TABLE[src[i]]) == 0)
			i++;

		if (i > org)
			bufput(ob, src + org, i - org);

		/* escaping */
		if (i >= size)
			break;

		if (code < 7) { /* multibyte UTF-8 or escaped character */
			if (code > size - i) {
				/* truncated UTF-8 character */
				bufputc(ob, '?');
				break;
			} else {
				unsigned int chr = src[i++];

				chr &= 0xff >> code;
				while (--code)
					chr = (chr << 6) + (src[i++] & 0x3f);

				if (chr < 0x80) {
					code = XML_LOOKUP_TABLE[chr];
					if (code)
						bufputs(ob, LOOKUP_CODES[code]);
					else
						bufputc(ob, chr);
				} else if (chr < 0xd800 ||
				           (chr >= 0xe000 && chr <= 0xfffd) ||
				           (chr >= 0x10000 && chr <= 0x10ffff))
				{
					bufprintf(ob, "&#x%x;", chr);
				} else {
					bufputc(ob, '?');
				}
			}
		} else {
			bufputs(ob, LOOKUP_CODES[code]);
			i++;
		}
	}
}
