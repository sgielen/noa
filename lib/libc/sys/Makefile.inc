.PATH: ${.CURDIR}/sys

SRCS+=	syscalls.h syscalls.S
CLEANFILES+=syscalls.h syscalls.S Symbol-sys.map

SYMBOL_MAPS+=Symbol-sys.map

syscalls.h: ${.CURDIR}/sys/gensyshdr.awk ${.CURDIR}/../../kern/syscalls
	${.CURDIR}/sys/gensyshdr.awk \
		${.CURDIR}/../../kern/syscalls > ${.TARGET}

syscalls.S: ${.CURDIR}/sys/gensysasm.awk ${.CURDIR}/../../kern/syscalls
	${.CURDIR}/sys/gensysasm.awk \
		${.CURDIR}/../../kern/syscalls > ${.TARGET}

Symbol-sys.map: ${.CURDIR}/sys/gensysmap.awk ${.CURDIR}/../../kern/syscalls
	${.CURDIR}/sys/gensysmap.awk \
		${.CURDIR}/../../kern/syscalls > ${.TARGET}
