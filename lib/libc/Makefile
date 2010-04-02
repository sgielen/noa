SHLIB_NAME=libc.so

CFLAGS+=-nostdinc -std=c99 -I. -Imachdep/${MACHINE_ARCH} \
	-I${.CURDIR}/../../include \
	-I${.CURDIR}/../../include/machdep/${MACHINE_ARCH}

VERSION_DEF=${.CURDIR}/Versions.def

WARNS?=	6

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

.include <bsd.lib.mk>
