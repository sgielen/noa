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
#include <kernel_machdep.h>

#define	M_RLOCKMASK	0x80000000
#define	M_WLOCK		(~M_RLOCKMASK)

void
mutex_assert(struct mutex *m __unused)
{
}

void
mutex_destroy(struct mutex *m __unused)
{
}

void
mutex_init(struct mutex *m __unused)
{

#ifdef SMP
	m->m_flags = 0;
#endif
}

void
mutex_slock(struct mutex *m __unused)
{
#ifdef SMP
	long flags;
#endif

	cpu_critical_enter();
#ifdef SMP
	do {
		flags = m->m_flags & M_RLOCKMASK;
	} while (!atomic_cmpset_long(&m->m_flags, flags, flags + 1));
#endif
}

void
mutex_sunlock(struct mutex *m __unused)
{

#ifdef SMP
	atomic_add_long(&m->m_flags, -1);
#endif
	cpu_critical_leave();
}

void
mutex_xlock(struct mutex *m __unused)
{

	cpu_critical_enter();
#ifdef SMP
	while (!atomic_cmpset_long(&m->m_flags, 0, M_WLOCK));
#endif
}

void
mutex_xunlock(struct mutex *m __unused)
{

#ifdef SMP
	m->m_flags = 0;
#endif
	cpu_critical_leave();
}
