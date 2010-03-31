#!/usr/bin/awk -f

BEGIN {
	printf "NOA_1.0 {\n";
}

/^SYSCALL/ {
	name = $3;
}

/^PUBLIC/ {
	printf "\t%s;\n", name;
}

END {
	printf "};\n";
}
