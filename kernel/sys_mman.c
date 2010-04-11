/*-
 * Copyright (c) 2010 The Noa Project, http://noap __unusedroject.org/
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

#include "syscalls.h"

int
sys_mmap(struct thread *td __unused,
    struct sys_mmap_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_munmap(struct thread *td __unused,
    struct sys_munmap_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_mlock(struct thread *td __unused,
    struct sys_mlock_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_munlock(struct thread *td __unused,
    struct sys_munlock_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_mlockall(struct thread *td __unused,
    struct sys_mlockall_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_munlockall(struct thread *td __unused,
    struct sys_munlockall_args *ap __unused)
{

	return (ENOSYS);
}

int
sys_mprotect(struct thread *td __unused,
    struct sys_mprotect_args *ap __unused)
{

	return (ENOSYS);
}
