.PATH: ${.CURDIR}/unistd

SRCS+=	chown.c dup.c execv.c fchown.c getpgrp.c isatty.c lchown.c \
	link.c read.c readlink.c readv.c rmdir.c symlink.c tcgetpgrp.c \
	tcsetpgrp.c unlink.c write.c writev.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
