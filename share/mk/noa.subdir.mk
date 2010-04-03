_SUBDIR: .USE
	@for entry in ${SUBDIR}; do \
		echo "===> ${DIRPRFX}$$entry (${.TARGET})"; \
		${MAKE} -C ${.CURDIR}/$${entry} ${.TARGET} \
		    DIRPRFX=${DIRPRFX}$${entry}/; \
	done

.for __target in all clean
${__target}: _SUBDIR
.endfor
