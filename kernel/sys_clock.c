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
#include <time.h>

#include "syscalls.h"

static struct timespec realtime_offset;

int
sys_clock_gettime(struct thread *td __unused,
    struct sys_clock_gettime_args *ap)
{
	struct timespec ts;

	switch (ap->clock_id) {
	case CLOCK_MONOTONIC:
		clockhw_read(&ts);
		return (copyout(&ts, ap->tp, sizeof ts));
	case CLOCK_REALTIME:
		clockhw_read(&ts);
		timespec_add(&ts, &realtime_offset);
		return (copyout(&ts, ap->tp, sizeof ts));
	default:
		return (EINVAL);
	}
}

int
sys_clock_settime(struct thread *td, struct sys_clock_settime_args *ap)
{
	struct timespec tm, tr;
	int error;

	if (ap->clock_id != CLOCK_REALTIME)
		return (EINVAL);
	if ((error = priv_check(td, PRIV_CLOCK_SETTIME)) != 0)
		return (error);
	if ((error = copyin(ap->tp, &tr, sizeof tr)) != 0)
		return (error);
	clockhw_read(&tm);
	timespec_sub(&tr, &tm);
	realtime_offset = tr;
	return (0);
}

int
sys_clock_nanosleep(struct thread *td __unused,
    struct sys_clock_nanosleep_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_clock_getres(struct thread *td __unused,
    struct sys_clock_getres_args *ap __unused)
{

	return (ENOSYS);
}
