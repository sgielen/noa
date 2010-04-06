PROG=	as
NO_MAN=

WARNS?=	3

YASM=${.CURDIR}/../../contrib/yasm
.PATH: ${YASM} ${YASM}/frontends/yasm ${YASM}/libyasm \
	${YASM}/modules/arch/x86 ${YASM}/modules/dbgfmts/dwarf2 \
	${YASM}/modules/objfmts/elf ${YASM}/modules/parsers/gas \
	${YASM}/modules/preprocs/raw

CFLAGS+=-I${YASM} -I${YASM}/libyasm -DHAVE_CONFIG_H

SRCS= \
	assocdat.c bc-align.c bc-data.c bc-incbin.c bc-org.c \
	bc-reserve.c bitvect.c bytecode.c dwarf2-aranges.c \
	dwarf2-dbgfmt.c dwarf2-info.c dwarf2-line.c elf-objfmt.c \
	elf-x86-amd64.c elf-x86-x86.c elf.c errwarn.c expr.c file.c \
	floatnum.c gas-parse.c gas-parser.c gas-token.c hamt.c insn.c \
	intnum.c inttree.c linemap.c md5.c mergesort.c module.c \
	phash.c raw-preproc.c section.c strcasecmp.c strsep.c symrec.c \
	valparam.c value.c x86arch.c x86bc.c x86cpu.c x86expr.c \
	x86id.c x86regtmod.c xmalloc.c xstrdup.c yasm-options.c yasm.c

.include <bsd.prog.mk>
