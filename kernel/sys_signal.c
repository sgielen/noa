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

static int
kill_process(struct process *p __unused, int sig __unused)
{

	return (ENOSYS);
}

static int
kill_processgroup(struct processgroup *pg __unused, int sig __unused)
{

	return (ENOSYS);
}

static int
kill_all(int sig __unused)
{

	return (ENOSYS);
}

int
sys_kill(struct thread *td, struct sys_kill_args *ap)
{
	struct processgroup *pg;
	struct process *p;
	int error = ESRCH;

	if (ap->pid < -1) {
		/* Signal process group. */
		mutex_slock(&processtopo);
		pg = processgroup_lookup(-ap->pid);
		if (pg != NULL)
			error = kill_processgroup(pg, ap->sig);
		mutex_sunlock(&processtopo);
	} else if (ap->pid == -1) {
		/* Signal all processes. */
		error = kill_all(ap->sig);
	} else if (ap->pid == 0) {
		/* Signal current process group. */
		mutex_slock(&processtopo);
		pg = td->td_process->p_group;
		error = kill_processgroup(pg, ap->sig);
		mutex_sunlock(&processtopo);
	} else {
		/* Signal process. */
		mutex_slock(&processtopo);
		p = process_lookup(ap->pid);
		if (p != NULL)
			error = kill_process(p, ap->sig);
		mutex_sunlock(&processtopo);
	}

	return (error);
}
