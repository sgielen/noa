LIB=	c

CFLAGS+=-I. -I${.CURDIR}/machdep/${MACHINE}

VERSION_DEF=${.CURDIR}/Versions.def

.include "${.CURDIR}/errno/Makefile.inc"
.include "${.CURDIR}/fcntl/Makefile.inc"
.include "${.CURDIR}/select/Makefile.inc"
.include "${.CURDIR}/stat/Makefile.inc"
.include "${.CURDIR}/stdio/Makefile.inc"
.include "${.CURDIR}/stdlib/Makefile.inc"
.include "${.CURDIR}/string/Makefile.inc"
.include "${.CURDIR}/sys/Makefile.inc"
.include "${.CURDIR}/termios/Makefile.inc"
.include "${.CURDIR}/time/Makefile.inc"
.include "${.CURDIR}/unistd/Makefile.inc"

.include <noa.lib.mk>
