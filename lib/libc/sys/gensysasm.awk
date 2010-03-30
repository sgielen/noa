#!/usr/bin/awk -f

BEGIN {
	printf "#include \"SYS.h\"\n\n";
}

/^SYSCALL/ {
	printf "SYSCALL(%d, %s)\n", $2, $3;
	name = $3;
}
