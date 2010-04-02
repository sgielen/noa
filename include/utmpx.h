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

#ifndef _UTMPX_H_
#define	_UTMPX_H_

#define	__NEED_PID_T
#define	__NEED_STRUCT_TIMEVAL

#include <noa/cdefs.h>
#include <noa/types.h>

#define	EMPTY		0
#define	BOOT_TIME	1
#define	OLD_TIME	2
#define	NEW_TIME	3
#define	USER_PROCESS	4
#define	INIT_PROCESS	5
#define	LOGIN_PROCESS	6
#define	DEAD_PROCESS	7

struct utmpx {
	short		ut_type;
	struct timeval	ut_tv;
	char		ut_id[8];
	pid_t		ut_pid;
	char		ut_user[32];
	char		ut_line[32];
};

__BEGIN_DECLS
void	 endutxent(void);
struct utmpx *
	 getutxent(void);
struct utmpx *
	 getutxid(const struct utmpx *);
struct utmpx *
	 getutxline(const struct utmpx *);
struct utmpx *
	 pututxline(const struct utmpx *);
void	 setutxent(void);
__END_DECLS

#endif /* !_UTMPX_H_ */
