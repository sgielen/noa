/*-
 * Copyright (c) 2010 The Noa Project, http://noaproject.org/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <noa/atomic.h>
#include <kernel.h>

/*
 * Cookies.
 *
 * Cookies are identifiers used throughout the kernel for various
 * objects, such as processes, threads and file descriptors. Numbers are
 * allocated from a single namespace.
 *
 * Cookies are allocated using cookie_get() and are returned to the pool
 * using cookie_put(). This implementation never actually recycles
 * cookie numbers, which means cookie_put() is effectively a no-op.
 * Cookies are at least 63 bits. Overflowing cookie_next will take at
 * least centuries on common hardware.
 *
 * Cookies are handed out in sequential order, albeit in bitwise reverse
 * order. This is to make proper distribution in unbalanced trees more
 * likely. The top bit is always zero, in order to keep cookies positive
 * when cast to a signed integer type.
 */

static cookie_t cookie_next = 0;

__CTASSERT(sizeof(cookie_t) == 8);

cookie_t
cookie_get(void)
{
	cookie_t ret;

	ret = atomic_fetchadd_intmax_t(&cookie_next, 2);
	ret = (((ret & 0xaaaaaaaaaaaaaaaa) >> 1) |
	    ((ret & 0x5555555555555555) << 1));
	ret = (((ret & 0xcccccccccccccccc) >> 2) |
	    ((ret & 0x3333333333333333) << 2));
	ret = (((ret & 0xf0f0f0f0f0f0f0f0) >> 4) |
	    ((ret & 0x0f0f0f0f0f0f0f0f) << 4));
	ret = (((ret & 0xff00ff00ff00ff00) >> 8) |
	    ((ret & 0x00ff00ff00ff00ff) << 8));
	ret = (((ret & 0xffff0000ffff0000) >> 16) |
	    ((ret & 0x0000ffff0000ffff) << 16));
	return ((ret >> 32) | (ret << 32));
}
