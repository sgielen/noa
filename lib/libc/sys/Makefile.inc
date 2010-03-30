.PATH: ${.CURDIR}/sys

SRCS+=	syscalls.h syscalls.S
CLEANFILES+=syscalls.h syscalls.S

syscalls.h: ${.CURDIR}/sys/gensyshdr.awk ${.CURDIR}/../../kern/syscalls
	${.CURDIR}/sys/gensyshdr.awk \
		${.CURDIR}/../../kern/syscalls > ${.TARGET}

syscalls.S: ${.CURDIR}/sys/gensyshdr.awk ${.CURDIR}/../../kern/syscalls
	${.CURDIR}/sys/gensysasm.awk \
		${.CURDIR}/../../kern/syscalls > ${.TARGET}
