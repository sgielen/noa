CC?=	cc
CFLAGS?=-O3

.SUFFIXES: .o .c .S

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}
.S.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}
