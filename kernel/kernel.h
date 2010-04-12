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

#ifndef _KERNEL_H_
#define	_KERNEL_H_

#define	__NEED_COOKIE_T
#define	__NEED_NULL
#define	__NEED_PID_T

#include <noa/types.h>

/*
 * Kernel data structures.
 */

struct cond;
struct filedescriptor;
struct mutex;
struct process;
struct processgroup;
struct session;
struct thread;
struct timespec;

typedef unsigned long refcount_t;

struct cond {
	void		*cv_dummy;
};

struct filedescriptor {
	struct process	*fd_service;
	cookie_t	 fd_cookie;
	refcount_t	 fd_refcount;
};

struct mutex {
	void		*m_dummy;
};

struct process {
	struct process	*p_parent;
	struct processgroup *p_group;
	pid_t		 p_id;
};

struct processgroup {
	struct session	*pg_session;
	pid_t		 pg_id;
};

struct session {
	pid_t		 s_id;
};

struct thread {
	struct process	*td_process;
};

/*
 * Kernel subroutines.
 */

#define	COND_ONE	0x1
#define	COND_SIG	0x2

void	 cond_init(struct cond *);
void	 cond_destroy(struct cond *);
void	 cond_signal(struct cond *, int);
void	 cond_wait(struct cond *, struct mutex *,
	     const struct timespec *, int);

void	 mutex_assert(struct mutex *);
void	 mutex_destroy(struct mutex *);
void	 mutex_init(struct mutex *);
void	 mutex_lock(struct mutex *);
void	 mutex_unlock(struct mutex *);

struct process *
	 process_lookup(pid_t);

/*
 * Global variables.
 */

extern struct mutex process_layout;

#endif /* !_KERNEL_H_ */
