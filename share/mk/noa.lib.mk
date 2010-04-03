.include <noa.sys.mk>

CFLAGS+=-fpic

LDFLAGS+=-Wl,--version-script=Version.map -nostdlib -shared -Wl,-x

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: lib${LIB}.so

Version.map: ${VERSION_DEF} ${SYMBOL_MAPS}
	cat ${SYMBOL_MAPS} | awk -v vfile=${VERSION_DEF} \
		-f /usr/share/mk/version_gen.awk > ${.TARGET}

lib${LIB}.so: ${OBJS} Version.map
	${CC} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f lib${LIB}.so Version.map ${OBJS} ${CLEANFILES}
