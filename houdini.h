#ifndef __HOUDINI_H__
#define __HOUDINI_H__

#include "buffer.h"

extern void houdini_escape_html(struct buf *ob, const char *src, size_t size);
extern void houdini_unescape_html(struct buf *ob, const char *src, size_t size);
extern void houdini_escape_uri(struct buf *ob, const char *src, size_t size);
extern void houdini_escape_url(struct buf *ob, const char *src, size_t size);
extern void houdini_unescape_uri(struct buf *ob, const char *src, size_t size);
extern void houdini_unescape_url(struct buf *ob, const char *src, size_t size);

#endif
