SRCS+=	cookie.c mutex.c process.c sys_clock.c sys_fildes.c sys_mman.c \
	sys_proc.c sys_tty.c sys_vfs.c

SRCS+=	syscallvec.c syscalls.h
CLEANFILES+=syscallvec.c syscalls.h

CFLAGS+=-I${.CURDIR} -DSMP

.include "${.CURDIR}/machdep/${MACHINE}/Makefile.inc"

syscallvec.c: ${.CURDIR}/gensysvec.awk ${.CURDIR}/syscalls
	${.CURDIR}/gensysvec.awk ${.CURDIR}/syscalls > ${.TARGET}

syscalls.h: ${.CURDIR}/gensysprotos.awk ${.CURDIR}/syscalls
	${.CURDIR}/gensysprotos.awk ${.CURDIR}/syscalls > ${.TARGET}

.include <noa.kernel.mk>
