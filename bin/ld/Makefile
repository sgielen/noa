PROG_CXX=ld
NO_MAN=

WARNS?=	0

BINUTILS=${.CURDIR}/../../contrib/binutils
.PATH: ${BINUTILS}/bfd ${BINUTILS}/elfcpp ${BINUTILS}/gold ${BINUTILS}/include ${BINUTILS}/libiberty

CFLAGS+=-I${.CURDIR} -I${BINUTILS}/elfcpp -I${BINUTILS}/gold -I${BINUTILS}/include
CFLAGS+=-DBINDIR=\"/nonexistent\" -DTOOLBINDIR=\"/nonexistent\" -DHAVE_CONFIG_H

LDADD+=	-lz

YACC=	bison

SRCS = \
	ansidecl.h archive.cc archive.h argv.c bfdver.h binary-io.h \
	binary.cc binary.h common.cc common.h compressed_output.cc \
	compressed_output.h copy-relocs.cc copy-relocs.h cp-demangle.c \
	cp-demangle.h cplus-dem.c crc32.c cref.cc cref.h debug.h \
	defstd.cc defstd.h demangle.h descriptors.cc descriptors.h \
	dirsearch.cc dirsearch.h dwarf.h dwarf_reader.cc \
	dwarf_reader.h dynobj.cc dynobj.h ehframe.cc ehframe.h \
	elfcpp.h elfcpp_file.h elfcpp_internal.h elfcpp_swap.h \
	errors.cc errors.h expression.cc filename_cmp.c filenames.h \
	fileread.cc fileread.h freebsd.h gc.cc gc.h getruntime.c \
	gold-threads.cc gold-threads.h gold.cc gold.h hex.c icf.cc \
	icf.h incremental.cc incremental.h layout.cc layout.h \
	lbasename.c libiberty.h lrealpath.c main.cc mapfile.cc \
	mapfile.h md5.c md5.h merge.cc merge.h mremap.c object.cc \
	object.h options.cc options.h output.cc output.h parameters.cc \
	parameters.h plugin-api.h plugin.cc plugin.h readsyms.cc \
	readsyms.h reduced_debug_output.cc reduced_debug_output.h \
	reloc-types.h reloc.cc reloc.h resolve.cc safe-ctype.c \
	safe-ctype.h script-c.h script-sections.cc script-sections.h \
	script.cc script.h sha1.c sha1.h stringpool.cc stringpool.h \
	symtab.cc symtab.h target-reloc.h target-select.cc \
	target-select.h target.cc target.h tls.h token.h \
	unlink-if-ordinary.c version.cc workqueue-internal.h \
	workqueue-threads.cc workqueue.cc workqueue.h x86_64.cc \
	x86_64.h xexit.c xmalloc.c xstrdup.c yyscript.y \
	\
	config.h

.include <bsd.prog.mk>
