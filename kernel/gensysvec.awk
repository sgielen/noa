#!/usr/bin/awk -f

BEGIN {
	printf "#include \"syscalls.h\"\n\n";
	printf "int (*syscallvec[])(struct thread *, void *) = {\n";
}

/^SYSCALL/ {
	printf "\t[%d] = (void *)sys_%s,\n", $2, $3;
}

END {
	printf "};\n";
}
