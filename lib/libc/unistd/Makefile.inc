.PATH: ${.CURDIR}/unistd

SRCS+=	dup.c fchown.c isatty.c link.c read.c readlink.c readv.c \
	rmdir.c symlink.c unlink.c write.c writev.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
