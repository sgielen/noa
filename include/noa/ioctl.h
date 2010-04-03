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

#ifndef _NOA_IOCTL_H_
#define	_NOA_IOCTL_H_

#include <noa/cdefs.h>

#define	_IOC_VOID	0x00000000
#define	_IOC_IN		0x00000001
#define	_IOC_OUT	0x00000002
#define	_IOC_INOUT	(IOC_IN|IOC_OUT)

#define	_IOC(inout, size, group, num) \
	((size) << 17 | (group) << 10 | (num) << 2 | (inout))
#define	_IO(group, num)		_IOC(_IOC_VOID, 0, (group), (num))
#define	_IOR(group, num, type)	_IOC(_IOC_OUT, sizeof(type), (group), (num))
#define	_IOW(group, num, type)	_IOC(_IOC_IN, sizeof(type), (group), (num))
#define	_IORW(group, num, type)	_IOC(_IOC_INOUT, sizeof(type), (group), (num))

/* TTYs. */
#define	TCGETA		_IOR('t', 1, struct termios)
#define	TCSETAN		_IOW('t', 2, struct termios)
#define	TCSETAD		_IOW('t', 3, struct termios)
#define	TCSETAF		_IOW('t', 4, struct termios)
#define	TCDRAIN		 _IO('t', 5)
#define	TCFLUSH		_IOW('t', 6, int)
#define	TCGETSID	_IOR('t', 7, pid_t)

#endif /* !_NOA_IOCTL_H_ */
