.PATH: ${.CURDIR}/unistd

SRCS+=	_exit.c chown.c dup.c dup2.c execv.c fchown.c fsync.c \
	getpgrp.c isatty.c lchown.c link.c pread.c pwrite.c read.c \
	readlink.c rmdir.c symlink.c tcgetpgrp.c tcsetpgrp.c unlink.c \
	write.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
