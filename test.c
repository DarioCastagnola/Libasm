#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *buf;

	buf = strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("%s\n", buf);
	free(buf);
}

