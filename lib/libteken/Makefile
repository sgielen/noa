LIB=	teken
SRCS=	teken.c teken.h teken_state.h
CLEANFILES=teken_state.h

VERSION_DEF=${.CURDIR}/../libc/Versions.def

teken_state.h: gensequences sequences
	awk -f gensequences sequences > ${.TARGET}

.include <noa.lib.mk>
