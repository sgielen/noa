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

#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>

pid_t
waitpid(pid_t pid, int *stat_loc, int options)
{
	idtype_t idt;
	id_t id;
	siginfo_t si;

	if (options & ~(WCONTINUED|WNOHANG|WUNTRACED)) {
		errno = EINVAL;
		return (-1);
	}

	if (pid < -1) {
		idt = P_PGID;
		id = -pid;
	} else if (pid == -1) {
		idt = P_ALL;
	} else if (pid == 0) {
		idt = P_PGID;
		id = getpgrp();
	} else {
		idt = P_PID;
		id = pid;
	}

	options |= WEXITED;
	if (waitid(idt, id, &si, options) == -1)
		return (-1);

	if (stat_loc != NULL) {
		switch (si.si_code) {
		case CLD_EXITED:
			*stat_loc = __WIFEXITED;
			break;
		case CLD_STOPPED:
			*stat_loc = __WIFSTOPPED;
			break;
		case CLD_CONTINUED:
			*stat_loc = __WIFCONTINUED;
			break;
		default:
			*stat_loc = __WIFSIGNALED;
			break;
		}
		*stat_loc |= si.si_status << 8;
	}
	return (si.si_pid);
}
