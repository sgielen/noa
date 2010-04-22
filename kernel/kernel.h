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
#define	__NEED_STRUCT_TIMESPEC

#include <noa/astack.h>
#include <noa/tree.h>
#include <noa/types.h>
#include <limits.h>

/*
 * Kernel data structures.
 */

struct cond;
struct filedesc;
struct filehnd;
struct mutex;
struct process;
struct processgroup;
struct session;
struct slab;
struct slabentry;
struct thread;

typedef unsigned long refcount_t;

/*
 * Use TLS for per-CPU variables.
 */

#ifdef NO_SMP
#define	__percpu
#else
#define	__percpu	__thread
#endif

/*
 * Locking of kernel data structures.
 *
 * (a) Atomic operations.
 * (c) Constant.
 * (l) Locked by process_layout.
 * (p) Locked by p_lock.
 */

TREE_HEAD(filedesctable, filedesc);

struct cond {
	void		*cv_dummy;
};

struct filedesc {
	TREE_ENTRY(filedesc) fd_tree;	/* (p) Tree linkage. */
	struct filehnd	*fd_handle;	/* (c) Underlying file handle. */
	int		 fd_flags;	/* (a) File descriptor flags. */
};

struct filehnd {
	struct process	*fh_service;	/* (c) Responsible handler. */
	cookie_t	 fh_cookie;	/* (c) Identifier. */
	refcount_t	 fh_refcount;	/* (a) Reference count. */
};

struct mutex {
#ifndef NO_SMP
	volatile unsigned long m_flags;
#endif
};

struct process {
	struct mutex	 p_lock;	/* Per-process lock. */
	struct process	*p_parent;	/* (l) Parent process. */
	struct processgroup *p_group;	/* (l) Process group. */
	cookie_t	 p_id;		/* (c) Process identifier. */
	struct filedesctable p_fd;	/* (p) File descriptor table. */
	mode_t		 p_umask;	/* (a) File mode creation mask. */
};

struct processgroup {
	TREE_ENTRY(processgroup) pg_tree; /* (l) Process group tree. */
	struct session	*pg_session;	/* (c) Session. */
	cookie_t	 pg_id;		/* (c) Process group identifier. */
};

struct session {
	cookie_t	 s_id;		/* (c) Session identifier. */
	refcount_t	 s_refcount;	/* (a) Number of process groups. */
	char		 s_login[LOGIN_NAME_MAX]; /* (l) User name. */
};

struct slab {
	ASTACK_HEAD(, slabentry) sl_freelist; /* (a) Free list. */
	size_t		 sl_size;	/* (c) Allocation size. */
	void		(*sl_ctor)(void *); /* (c) Constructor. */
};

struct thread {
	TREE_ENTRY(thread) td_tree;	/* (l) Thread tree. */
	struct process	*td_process;	/* (c) Process. */
	cookie_t	 td_id;		/* (c) Thread identifier. */
};

/*
 * Machine-dependent subroutines.
 */

void	 clockhw_getres(struct timespec *);
void	 clockhw_read(struct timespec *);
int	 copyin(const void *, void *, size_t);
int	 copyout(const void *, void *, size_t);
void	 cpu_critical_enter(void);
void	 cpu_critical_leave(void);

/*
 * Kernel interfaces.
 */

#define	COND_ONE		0x1
#define	COND_SIG		0x2

void	 cond_init(struct cond *);
void	 cond_destroy(struct cond *);
void	 cond_signal(struct cond *, int);
void	 cond_wait(struct cond *, struct mutex *,
	     const struct timespec *, int);

cookie_t cookie_get(void);
#define	cookie_put(c)		((void)0)

#ifdef NO_SMP
#define	MUTEX_INITIALIZER	{ }

#define	mutex_assert(m)		((void)0)
#define	mutex_destroy(m)	((void)0)
#define	mutex_init(m)		((void)0)
#define	mutex_slock(m)		cpu_critical_enter()
#define	mutex_sunlock(m)	cpu_critical_leave()
#define	mutex_xlock(m)		cpu_critical_enter()
#define	mutex_xunlock(m)	cpu_critical_leave()
#else /* !NO_SMP */
#define	MUTEX_INITIALIZER	{ 0 }

void	 mutex_assert(struct mutex *);
void	 mutex_destroy(struct mutex *);
void	 mutex_init(struct mutex *);
void	 mutex_slock(struct mutex *);
void	 mutex_sunlock(struct mutex *);
void	 mutex_xlock(struct mutex *);
void	 mutex_xunlock(struct mutex *);
#endif /* NO_SMP */

#define	PRIV_CLOCK_SETTIME	1

int	 priv_check(struct thread *, int);

struct process *
	 process_lookup(cookie_t);

struct processgroup *
	 processgroup_lookup(cookie_t);

void	*slab_alloc_nowait(struct slab *);
void	*slab_alloc_waitok(struct slab *);
void	 slab_free(struct slab *, void *);
void	 slab_give(void *);
void	 _slab_init(struct slab *, size_t, void (*)(void *));
#define	slab_init(s, t, c) \
	_slab_init((s), sizeof(t), (void *)(c))

struct thread *
	 thread_lookup(cookie_t);

/*
 * Kernel utility functions.
 */

unsigned int
	 log2ceil(unsigned long);
unsigned int
	 log2floor(unsigned long);
void	 printf(const char *restrict, ...);
void	 putchar(char);
void	 timespec_add(struct timespec *, const struct timespec *);
void	 timespec_sub(struct timespec *, const struct timespec *);

/*
 * Global variables.
 */

extern struct mutex processtopo;

#endif /* !_KERNEL_H_ */
