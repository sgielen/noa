_SUBDIR: .USE
	for entry in ${SUBDIR}; do \
		${MAKE} -C ${.CURDIR}/$${entry} ${.TARGET}; \
	done

.for __target in all clean
${__target}: _SUBDIR
.endfor
