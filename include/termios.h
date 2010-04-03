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

#ifndef _TERMIOS_H_
#define	_TERMIOS_H_

#define	__NEED_PID_T

#include <noa/types.h>

#define	BRKINT		0x0001
#define	ICRNL		0x0002
#define	IGNBRK		0x0004
#define	IGNCR		0x0008
#define	IGNPAR		0x0010
#define	INLCR		0x0020
#define	INPCK		0x0040
#define	ISTRIP		0x0080
#define	IXANY		0x0100
#define	IXOFF		0x0200
#define	IXON		0x0400
#define	PARMRK		0x0800

#define	OPOST		0x0001

#define	CSIZE		0x0003
#define	    CS5		0x0000
#define	    CS6		0x0001
#define	    CS7		0x0002
#define	    CS8		0x0003
#define	CSTOPB		0x0004
#define	CREAD		0x0008
#define	PARENB		0x0010
#define	PARODD		0x0020
#define	HUPCL		0x0040
#define	CLOCAL		0x0080

#define	ECHO		0x0001
#define	ECHOE		0x0002
#define	ECHOK		0x0004
#define	ECHONL		0x0008
#define	ICANON		0x0010
#define	IEXTEN		0x0020
#define	ISIG		0x0040
#define	NOFLSH		0x0080
#define	TOSTOP		0x0100

#define	VEOF		0
#define	VEOL		1
#define	VERASE		2
#define	VINTR		3
#define	VKILL		4
#define	VMIN		5
#define	VQUIT		6
#define	VSTART		7
#define	VSTOP		8
#define	VSUSP		9
#define	VTIME		10
#define	NCCS		11

#define	B0		0
#define	B50		50
#define	B75		75
#define	B110		110
#define	B134		134
#define	B150		150
#define	B200		200
#define	B300		300
#define	B600		600
#define	B1200		1200
#define	B1800		1800
#define	B2400		2400
#define	B4800		4800
#define	B9600		9600
#define	B19200		19200
#define	B38400		38400

#define	TCSANOW		1
#define	TCSADRAIN	2
#define	TCSAFLUSH	3

#define	TCIFLUSH	0x1
#define	TCOFLUSH	0x2
#define	TCIOFLUSH	(TCIFLUSH|TCOFLUSH)

#define	TCIOFF		0x1
#define	TCION		0x2
#define	TCOOFF		0x4
#define	TCOON		0x8

typedef unsigned long	tcflag_t;
typedef unsigned char	cc_t;
typedef unsigned long	speed_t;

__ABI_STRUCT(termios, 64, {
	tcflag_t	c_iflag;
	tcflag_t	c_oflag;
	tcflag_t	c_cflag;
	tcflag_t	c_lflag;
	speed_t		__c_ispeed;
	speed_t		__c_ospeed;
	cc_t		c_cc[NCCS];
})

__BEGIN_DECLS
speed_t	 cfgetispeed(const struct termios *);
speed_t	 cfgetospeed(const struct termios *);
int	 cfsetispeed(struct termios *, speed_t);
int	 cfsetospeed(struct termios *, speed_t);
int	 tcdrain(int);
int	 tcflow(int, int);
int	 tcflush(int, int);
int	 tcgetattr(int, struct termios *);
pid_t	 tcgetsid(int);
int	 tcsendbreak(int, int);
int	 tcsetattr(int, int, const struct termios *);
__END_DECLS

#endif /* !_TERMIOS_H_ */
