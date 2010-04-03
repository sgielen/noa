CC?=	clang
CFLAGS?=-O3

.if ${MACHINE} == "amd64"
MACHINE=x86_64
.elif ${MACHINE} == "i386"
MACHINE=x86_32
.endif

.SUFFIXES: .o .c .S

.c.o:
	@echo CC ${.TARGET}
	@${CC} ${CFLAGS} -c ${.IMPSRC}
.S.o:
	@echo AS ${.TARGET}
	@${CC} ${CFLAGS} -c ${.IMPSRC}
