LIB=bfd
NO_MAN=

WARNS?=	0

BINUTILS=${.CURDIR}/../../contrib/binutils
.PATH: ${BINUTILS}/bfd ${BINUTILS}/include ${BINUTILS}/libiberty

CFLAGS+=-I${.CURDIR} -I${BINUTILS}/bfd -I${BINUTILS}/include
CFLAGS+=-DBINDIR=\"/nonexistent\" -DTOOLBINDIR=\"/nonexistent\" -DDEBUGDIR=\"/nonexistent\"
CFLAGS+=-DHAVE_CONFIG_H -DDEFAULT_VECTOR=bfd_elf32_i386_vec -DSELECT_ARCHITECTURES='&bfd_i386_arch'
CFLAGS+=-DSELECT_VECS='&bfd_elf32_i386_vec,&i386linux_vec,&i386pei_vec,&bfd_elf32_little_generic_vec,&bfd_elf32_big_generic_vec'
CFLAGS+=-DHAVE_bfd_elf32_i386_vec -DHAVE_i386linux_vec -DHAVE_i386pei_vec -DHAVE_bfd_elf32_little_generic_vec
CFLAGS+=-DHAVE_bfd_elf32_big_generic_vec

LDADD+=


YACC=	bison -y

SRCS = \
	archive.c archures.c bfd.c bfdio.c bfdwin.c cache.c coffgen.c \
	corefile.c format.c init.c libbfd.c opncls.c reloc.c section.c \
	syms.c targets.c hash.c linker.c srec.c binary.c tekhex.c ihex.c \
	stabs.c stab-syms.c merge.c dwarf2.c simple.c compress.c verilog.c \
	elf32-i386.c elf-ifunc.c elf-vxworks.c elf32.c elf.c elflink.c \
	elf-attrs.c elf-strtab.c elf-eh-frame.c dwarf1.c i386linux.c aout32.c \
	pei-i386.c peigen.c cofflink.c elf32-gen.c cpu-i386.c \
	\
	config.h

.include <noa.lib.mk>
