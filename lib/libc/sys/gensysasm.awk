#!/usr/bin/awk -f

BEGIN {
	printf "#include \"SYS.h\"\n\n";
}

/^SYSCALL/ {
	number = $2;
	name = $3;
	public = 0;
}

/^PUBLIC/ {
	public = 1;
}

/^END/ {
	if (public)
		printf "SYSCALL(%d, %s)\n", number, name;
	else
		printf "SYSCALL(%d, sys_%s)\n", number, name;
}
