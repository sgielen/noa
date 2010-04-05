PROG_CXX=ld
NO_MAN=

WARNS?=	0

BINUTILS=${.CURDIR}/../../contrib/binutils
.PATH: ${BINUTILS}/gold ${BINUTILS}/libiberty

CFLAGS+=-I${.CURDIR} -I${BINUTILS}/elfcpp -I${BINUTILS}/gold -I${BINUTILS}/include
CFLAGS+=-DBINDIR=\"/nonexistent\" -DTOOLBINDIR=\"/nonexistent\" -DHAVE_CONFIG_H

LDADD+=	-lz

YACC=	bison

SRCS= \
	archive.cc argv.c binary.cc common.cc compressed_output.cc \
	copy-relocs.cc cp-demangle.c cplus-dem.c crc32.c cref.cc \
	defstd.cc descriptors.cc dirsearch.cc dwarf_reader.cc \
	dynobj.cc ehframe.cc errors.cc expression.cc filename_cmp.c \
	fileread.cc gc.cc getruntime.c gold-threads.cc gold.cc hex.c \
	icf.cc incremental.cc layout.cc lbasename.c lrealpath.c \
	main.cc mapfile.cc md5.c merge.cc mremap.c object.cc \
	options.cc output.cc parameters.cc plugin.cc readsyms.cc \
	reduced_debug_output.cc reloc.cc resolve.cc safe-ctype.c \
	script-sections.cc script.cc sha1.c stringpool.cc symtab.cc \
	target-select.cc target.cc unlink-if-ordinary.c version.cc \
	workqueue-threads.cc workqueue.cc x86_64.cc xexit.c xmalloc.c \
	xstrdup.c yyscript.y

.include <bsd.prog.mk>
