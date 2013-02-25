# GNU Makefile
# Copyright (C) 2012 Przemyslaw Pawelczyk <przemoc@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SRCS := buffer.c houdini_href_e.c houdini_html_e.c houdini_html_u.c houdini_js_e.c houdini_js_u.c houdini_uri_e.c houdini_uri_u.c houdini_xml_e.c
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(addsuffix .d,$(basename $(SRCS)))
NAME := houdini

SRCDIR := $(dir $(lastword $(MAKEFILE_LIST)))
OBJDIR ?= ./
OBJS := $(addprefix $(OBJDIR),$(OBJS))
SLIB := lib$(NAME).a

vpath %.c $(SRCDIR)
vpath %.h $(SRCDIR)

AR ?= ar
CC ?= gcc
GPERF ?= gperf
SED ?= sed

CFLAGS ?= -O2
# -Wno-missing-field-initializers - gperf's header doesn't pass on -Wextra
MANDATORY_FLAGS := -Wall -Wextra -Wno-missing-field-initializers
override CFLAGS := $(MANDATORY_FLAGS) $(CFLAGS)

.PHONY: all clean objects package

all: package

objects: $(OBJS)
package: $(SLIB)

$(SLIB): $(OBJS)
	$(AR) rcs $@ $^

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<

%.d: %.c
	@set -e; \
	$(RM) $@; \
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) $< >$@.tmp; \
	$(SED) 's,\($*\)\.o[ :]*,$$(OBJDIR)\1.o $@: ,g' <$@.tmp >$@; \
	$(RM) $@.tmp

html_unescape.h: html_unescape.gperf
	$(GPERF) -t -N find_entity -H hash_entity -K entity -C -l --null-strings -m100 $< >$@

clean:
	$(RM) $(SLIB) $(OBJS) $(DEPS)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
