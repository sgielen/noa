SHLIB_NAME=libc.so

CFLAGS+=-nostdinc -I${.CURDIR}/../../include -std=c99 -I. -Imachine/amd64

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
.include "${.CURDIR}/unistd/Makefile.inc"

.include <bsd.lib.mk>
