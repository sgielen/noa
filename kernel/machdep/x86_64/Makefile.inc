.PATH: ${.CURDIR}/machdep/${MACHINE}

CFLAGS+=-I${.CURDIR}/machdep/${MACHINE}

SRCS+=	kinit.S kstartup.c intr.c
