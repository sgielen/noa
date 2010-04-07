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

#ifndef _SIGNAL_H_
#define	_SIGNAL_H_

#define	__NEED_PID_T
#define	__NEED_PTHREAD_ATTR_T
#define	__NEED_PTHREAD_T
#define	__NEED_SIGINFO_T
#define	__NEED_SIGSET_T
#define	__NEED_SIZE_T
#define	__NEED_STRUCT_TIMESPEC
#define	__NEED_UID_T
#define	__NEED_UNION_SIGVAL

#include <noa/types.h>

#define	SIG_DFL		1
#define	SIG_ERR		2
#define	SIG_IGN		3

#define	SIGEV_NONE	1
#define	SIGEV_SIGNAL	2
#define	SIGEV_THREAD	3

#define	SIGABRT		1
#define	SIGALRM		2
#define	SIGBUS		3
#define	SIGCHLD		4
#define	SIGCONT		5
#define	SIGFPE		6
#define	SIGHUP		7
#define	SIGILL		8
#define	SIGINT		9
#define	SIGKILL		10
#define	SIGPIPE		11
#define	SIGQUIT		12
#define	SIGSEGV		13
#define	SIGSTOP		14
#define	SIGTERM		15
#define	SIGTSTP		16
#define	SIGTTIN		17
#define	SIGTTOU		18
#define	SIGUSR1		19
#define	SIGUSR2		20
#define	SIGTRAP		21
#define	SIGURG		22
#define	SIGXCPU		23
#define	SIGXFSZ		24

__ABI_STRUCT(sigevent, 16, {
	int		 sigev_notify;
	int		 sigev_signo;
	union sigval	 sigev_value;
	void		(*sigev_notify_function)(union sigval);
	pthread_attr_t	*sigev_notify_attributes;
})

__ABI_STRUCT(sigaction, 16, {
	void	(*sa_handler)(int);
	sigset_t sa_mask;
	int	 sa_flags;
	void	(*sa_sigaction)(int, siginfo_t *, void *);
})

__BEGIN_DECLS
int	 kill(pid_t, int);
int	 killpg(pid_t, int);
void	 psiginfo(const siginfo_t *, const char *);
void	 psignal(int, const char *);
int	 pthread_kill(pthread_t, int);
int	 pthread_sigmask(int, const sigset_t *restrict,
	     sigset_t *restrict);
int	 raise(int);
int	 sigaction(int, const struct sigaction *restrict,
	     struct sigaction *restrict);
int	 sigaddset(sigset_t *, int);
int	 sigaltstack(const stack_t *restrict, stack_t *restrict);
int	 sigdelset(sigset_t *, int);
int	 sigemptyset(sigset_t *);
int	 sigfillset(sigset_t *);
int	 sigismember(const sigset_t *, int);
void	(*signal(int, void (*)(int)))(int);
int	 sigpending(sigset_t *);
int	 sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int	 sigqueue(pid_t, int, const union sigval);
int	 sigsuspend(const sigset_t *);
int	 sigtimedwait(const sigset_t *restrict, siginfo_t *restrict,
	     const struct timespec *restrict);
int	 sigwait(const sigset_t *restrict, int *restrict);
int	 sigwaitinfo(const sigset_t *restrict, siginfo_t *restrict);
__END_DECLS

#endif /* !_STDIO_H_ */
