LIB=	c

SRCS+=	sys_clock.c sys_mman.c sys_proc.c

SRCS+=	syscallvec.c syscalls.h
CLEAN_FILES+=syscallvec.c syscalls.h

.include "${.CURDIR}/machdep/${MACHINE}/Makefile.inc"

syscallvec.c: ${.CURDIR}/gensysvec.awk ${.CURDIR}/syscalls
	${.CURDIR}/gensysvec.awk ${.CURDIR}/syscalls > ${.TARGET}

syscalls.h: ${.CURDIR}/gensysprotos.awk ${.CURDIR}/syscalls
	${.CURDIR}/gensysprotos.awk ${.CURDIR}/syscalls > ${.TARGET}

.include <noa.kernel.mk>
