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

#include <errno.h>
#include <kernel.h>

#include "syscalls.h"

int
sys_getpid(struct thread *td, struct sys_getpid_args *ap __unused)
{

	td->td_retval = td->td_process->p_id;
	return (0);
}

int
sys_getppid(struct thread *td, struct sys_getppid_args *ap __unused)
{

	mutex_lock(&process_layout);
	td->td_retval = td->td_process->p_parent->p_id;
	mutex_unlock(&process_layout);
	return (0);
}

int
sys_getpgid(struct thread *td, struct sys_getpgid_args *ap)
{
	struct process *p;

	mutex_lock(&process_layout);
	if (ap->pid == 0) {
		p = td->td_process;
	} else {
		p = process_lookup(ap->pid);
		if (p == NULL) {
			mutex_unlock(&process_layout);
			return (ESRCH);
		}
	}
	td->td_retval = p->p_group->pg_id;
	mutex_unlock(&process_layout);
	return (0);
}

int
sys_getsid(struct thread *td __unused,
    struct sys_getsid_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_setsid(struct thread *td __unused,
    struct sys_setsid_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_waitid(struct thread *td __unused,
    struct sys_waitid_args *ap __unused)
{

	return (ENOSYS);
}

int
sys__Exit(struct thread *td __unused,
    struct sys__Exit_args *ap __unused)
{

	return (ENOSYS);
}
