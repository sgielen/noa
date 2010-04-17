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
#define	__NEED_MODE_T
#define	__NEED_NULL
#define	__NEED_SIZE_T

#include <noa/types.h>
#include <limits.h>

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

/*
 * Locking of kernel data structures.
 *
 * (a) Atomic operations.
 * (c) Constant.
 * (l) Locked by process_layout.
 * (p) Locked by p_lock.
 * (!) Not locked.
 */

struct cond {
	void		*cv_dummy;
};

struct filedescriptor {
	struct process	*fd_service;
	cookie_t	 fd_cookie;
	refcount_t	 fd_refcount;
};

struct mutex {
#ifndef NO_SMP
	volatile unsigned long m_flags;
#endif
};

struct process {
	struct process	*p_parent;	/* (l) Parent process. */
	struct processgroup *p_group;	/* (l) Process group. */
	struct mutex	 p_lock;	/* Per-process lock. */
	cookie_t	 p_id;		/* (c) Process identifier. */
	mode_t		 p_umask;	/* (!) File mode creation mask. */
};

struct processgroup {
	struct session	*pg_session;	/* (c) Session. */
	cookie_t	 pg_id;		/* (c) Process group identifier. */
};

struct session {
	cookie_t	 s_id;		/* (c) Session identifier. */
	refcount_t	 s_refcount;	/* (a) Number of process groups. */
	char		 s_login[LOGIN_NAME_MAX]; /* (l) User name. */
};

struct slab {
	void		*s_dummy;
};

struct thread {
	struct process	*td_process;	/* (c) Process. */
	cookie_t	 t_id;		/* (c) Thread identifier. */
};

/*
 * Machine-dependent subroutines.
 */
void	 cpu_critical_enter(void);
void	 cpu_critical_leave(void);

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

cookie_t cookie_get(void);
#define	cookie_put(c)		((void)0)

#ifdef NO_SMP
#define	mutex_assert(m)		((void)0)
#define	mutex_destroy(m)	((void)0)
#define	mutex_init(m)		((void)0)
#define	mutex_slock(m)		cpu_critical_enter()
#define	mutex_sunlock(m)	cpu_critical_leave()
#define	mutex_xlock(m)		cpu_critical_enter()
#define	mutex_xunlock(m)	cpu_critical_leave()
#else /* !NO_SMP */
void	 mutex_assert(struct mutex *);
void	 mutex_destroy(struct mutex *);
void	 mutex_init(struct mutex *);
void	 mutex_slock(struct mutex *);
void	 mutex_sunlock(struct mutex *);
void	 mutex_xlock(struct mutex *);
void	 mutex_xunlock(struct mutex *);
#endif /* NO_SMP */

struct process *
	 process_lookup(cookie_t);

void	*slab_alloc(struct slab *);
void	 slab_free(struct slab *, void *);
void	 _slab_init(struct slab *, size_t, void (*)(void *));
#define	slab_init(s, t, c) \
	_slab_init((s), sizeof(t), (void *)(c))

/*
 * Global variables.
 */

extern struct mutex process_layout;

#endif /* !_KERNEL_H_ */
