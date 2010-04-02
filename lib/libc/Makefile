SHLIB_NAME=libc.so

.if ${MACHINE_ARCH} == "amd64"
ARCH=x86_64
.elif ${MACHINE_ARCH} == "i386"
ARCH=x86_32
.endif

CFLAGS+=-nostdinc -std=c99 -I. -Imachdep/${ARCH} \
	-I${.CURDIR}/../../include \
	-I${.CURDIR}/../../include/machdep/${ARCH}

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
