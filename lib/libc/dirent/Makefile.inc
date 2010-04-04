.PATH: ${.CURDIR}/dirent

SRCS+=	alphasort.c dirfd.c fdopendir.c opendir.c readdir.c

SYMBOL_MAPS+=${.CURDIR}/dirent/Symbol.map
