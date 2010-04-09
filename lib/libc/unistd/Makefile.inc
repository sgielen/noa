.PATH: ${.CURDIR}/unistd

SRCS+=	_exit.c chown.c dup.c dup2.c execv.c fchown.c getpgrp.c \
	isatty.c lchown.c link.c read.c readlink.c readv.c rmdir.c \
	symlink.c tcgetpgrp.c tcsetpgrp.c unlink.c write.c writev.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
