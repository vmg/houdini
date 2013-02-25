/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

#include "buffer.h"

/* Used as default value for gh_buf->ptr so that people can always
 * assume ptr is non-NULL and zero terminated even for new gh_bufs.
 */
uint8_t gh_buf__initbuf[1];

uint8_t gh_buf__oom[1];

#define ENSURE_SIZE(b, d) \
	if ((d) > buf->asize && gh_buf_grow(b, (d)) < 0)\
		return -1;


void gh_buf_init(gh_buf *buf, size_t initial_size)
{
	buf->asize = 0;
	buf->size = 0;
	buf->ptr = gh_buf__initbuf;

	if (initial_size)
		gh_buf_grow(buf, initial_size);
}

int gh_buf_try_grow(gh_buf *buf, size_t target_size, bool mark_oom)
{
	uint8_t *new_ptr;
	size_t new_size;

	if (buf->ptr == gh_buf__oom)
		return -1;

	if (target_size <= buf->asize)
		return 0;

	if (buf->asize == 0) {
		new_size = target_size;
		new_ptr = NULL;
	} else {
		new_size = buf->asize;
		new_ptr = buf->ptr;
	}

	/* grow the buffer size by 1.5, until it's big enough
	 * to fit our target size */
	while (new_size < target_size)
		new_size = (new_size << 1) - (new_size >> 1);

	/* round allocation up to multiple of 8 */
	new_size = (new_size + 7) & ~7;

	new_ptr = realloc(new_ptr, new_size);

	if (!new_ptr) {
		if (mark_oom)
			buf->ptr = gh_buf__oom;
		return -1;
	}

	buf->asize = new_size;
	buf->ptr   = new_ptr;

	/* truncate the existing buffer size if necessary */
	if (buf->size >= buf->asize)
		buf->size = buf->asize - 1;
	buf->ptr[buf->size] = '\0';

	return 0;
}

void gh_buf_free(gh_buf *buf)
{
	if (!buf) return;

	if (buf->ptr != gh_buf__initbuf && buf->ptr != gh_buf__oom)
		free(buf->ptr);

	gh_buf_init(buf, 0);
}

void gh_buf_clear(gh_buf *buf)
{
	buf->size = 0;
	if (buf->asize > 0)
		buf->ptr[0] = '\0';
}

int gh_buf_set(gh_buf *buf, const uint8_t *data, size_t len)
{
	if (len == 0 || data == NULL) {
		gh_buf_clear(buf);
	} else {
		if (data != buf->ptr) {
			ENSURE_SIZE(buf, len + 1);
			memmove(buf->ptr, data, len);
		}
		buf->size = len;
		buf->ptr[buf->size] = '\0';
	}
	return 0;
}

int gh_buf_sets(gh_buf *buf, const uint8_t *string)
{
	return gh_buf_set(buf, string, string ? strlen((const char *)string) : 0);
}

int gh_buf_putc(gh_buf *buf, int c)
{
	ENSURE_SIZE(buf, buf->size + 2);
	buf->ptr[buf->size++] = c;
	buf->ptr[buf->size] = '\0';
	return 0;
}

int gh_buf_put(gh_buf *buf, const uint8_t *data, size_t len)
{
	ENSURE_SIZE(buf, buf->size + len + 1);
	memmove(buf->ptr + buf->size, data, len);
	buf->size += len;
	buf->ptr[buf->size] = '\0';
	return 0;
}

int gh_buf_puts(gh_buf *buf, const char *string)
{
	assert(string);
	return gh_buf_put(buf, (const uint8_t *)string, strlen(string));
}

uint8_t *gh_buf_detach(gh_buf *buf)
{
	uint8_t *data = buf->ptr;

	if (buf->asize == 0 || buf->ptr == gh_buf__oom)
		return NULL;

	gh_buf_init(buf, 0);

	return data;
}

void gh_buf_rtrim(gh_buf *buf)
{
	while (buf->size > 0) {
		if (!isspace(buf->ptr[buf->size - 1]))
			break;

		buf->size--;
	}

	buf->ptr[buf->size] = '\0';
}

int gh_buf_cmp(const gh_buf *a, const gh_buf *b)
{
	int result = memcmp(a->ptr, b->ptr, MIN(a->size, b->size));
	return (result != 0) ? result :
		(a->size < b->size) ? -1 : (a->size > b->size) ? 1 : 0;
}
