#!/usr/bin/awk -f

BEGIN {
	printf "#ifndef _SYSCALLS_H_\n#define\t_SYSCALLS_H_\n\n";
	printf "struct thread;\n";
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
	printf "struct sys_%s_args {\n", name;
}

/^ARG/ {
	split($0, a, " : ");

	printf "\t%s %s;\n", a[2], $2;
}

/^END/ {
	printf "};\n";
	printf "int sys_%s(struct thread *, struct sys_%s_args *);\n\n", name, name;
}

END {
	printf "#endif /* !_SYSCALLS_H_ */\n";
}
