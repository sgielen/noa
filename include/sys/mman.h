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

#ifndef _SYS_MMAN_H_
#define	_SYS_MMAN_H_

#define	__NEED_MODE_T
#define	__NEED_OFF_T
#define	__NEED_SIZE_T

#include <noa/cdefs.h>
#include <noa/types.h>

#define	PROT_NONE		0x0
#define	PROT_EXEC		0x1
#define	PROT_WRITE		0x2
#define	PROT_READ		0x4

#define	MAP_FIXED		0x1
#define	MAP_PRIVATE		0x2
#define	MAP_SHARED		0x4

#define	MS_ASYNC		1
#define	MS_INVALIDATE		2
#define	MS_SYNC			3

#define	MCL_CURRENT		1
#define	MCL_FUTURE		2

#define	POSIX_MADV_DONTNEED	1
#define	POSIX_MADV_NORMAL	3
#define	POSIX_MADV_RANDOM	4
#define	POSIX_MADV_SEQUENTIAL	5
#define	POSIX_MADV_WILLNEED	6

__BEGIN_DECLS
int	 mlock(const void *, size_t);
int	 mlockall(int);
void	*mmap(void *, size_t, int, int, int, off_t);
int	 mprotect(void *, size_t, int);
int	 msync(void *, size_t, int);
int	 munlock(const void *, size_t);
int	 munlockall(void);
int	 munmap(void *, size_t);
int	 posix_madvise(void *, size_t, int);
int	 shm_open(const char *, int, mode_t);
int	 shm_unlink(const char *);
__END_DECLS

#endif /* !_SYS_MMAN_H_ */
