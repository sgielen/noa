#!/usr/bin/awk -f

BEGIN {
	printf "#ifndef _SYSCALLS_H_\n#define\t_SYSCALLS_H_\n\n";
}

/^TYPE/ {
	printf "#define\t__NEED_%s\n", toupper($2);
}

/^STRUCT/ {
	printf "struct %s;\n", $2;
}

/^SYSCALL/ {
	if (!init) {
		printf "\n#include <noa/types.h>\n\n";
		init = 1;
	}
	name = $3;
}

/^RET/ {
	printf "%s\tsys_%s(", $2, name;
	narg = 0;
}

/^ARG/ {
	split($0, a, " : ");
	type = a[2];
	if (narg == 0) {
		printf "%s", type;
		narg++;
	} else {
		printf ", %s", type;
	}
}

/^END/ {
	if (narg == 0)
		printf "void);\n";
	printf ");\n";
}

END {
	printf "\n#endif /* !_SYSCALLS_H_ */\n";
}
