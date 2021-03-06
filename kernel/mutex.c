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

#define	M_WLOCK		0x80000000

void
mutex_assert(struct mutex *m __unused)
{
}

void
mutex_destroy(struct mutex *m __unused)
{
}

void
mutex_init(struct mutex *m)
{

	m->m_flags = 0;
}

void
mutex_slock(struct mutex *m)
{
	long flags;

	cpu_critical_enter();
	do {
		flags = m->m_flags & ~M_WLOCK;
	} while (!atomic_cmpset_long(&m->m_flags, flags, flags + 1));
}

void
mutex_sunlock(struct mutex *m)
{

	atomic_add_long(&m->m_flags, -1);
	cpu_critical_leave();
}

void
mutex_xlock(struct mutex *m)
{

	cpu_critical_enter();
	while (!atomic_cmpset_long(&m->m_flags, 0, M_WLOCK));
}

void
mutex_xunlock(struct mutex *m)
{

	m->m_flags = 0;
	cpu_critical_leave();
}
