SHLIB_NAME=libc.so

CFLAGS+=-nostdinc -I${.CURDIR}/../../include

VERSION_DEF=${.CURDIR}/Versions.def

WARNS?=	6

.include "${.CURDIR}/fcntl/Makefile.inc"
.include "${.CURDIR}/string/Makefile.inc"
.include "${.CURDIR}/stdlib/Makefile.inc"

.include <bsd.lib.mk>
