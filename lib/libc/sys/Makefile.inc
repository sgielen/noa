.PATH: ${.CURDIR}/sys

SRCS+=	syscalls.h syscalls.S
CLEANFILES+=syscalls.h syscalls.S Symbol-sys.map

SYMBOL_MAPS+=Symbol-sys.map

syscalls.h: ${.CURDIR}/sys/gensyshdr.awk ${.CURDIR}/../../kernekernel/syscalls
	${.CURDIR}/sys/gensyshdr.awk \
		${.CURDIR}/../../kernel/syscalls > ${.TARGET}

syscalls.S: ${.CURDIR}/sys/gensysasm.awk ${.CURDIR}/../../kernel/syscalls
	${.CURDIR}/sys/gensysasm.awk \
		${.CURDIR}/../../kernel/syscalls > ${.TARGET}

Symbol-sys.map: ${.CURDIR}/sys/gensysmap.awk ${.CURDIR}/../../kernel/syscalls
	${.CURDIR}/sys/gensysmap.awk \
		${.CURDIR}/../../kernel/syscalls > ${.TARGET}
