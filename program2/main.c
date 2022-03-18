#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t 
main(int32_t ac, char **av)
{
    char buf[256u];

    while (true) {
	fprintf(stdout, ">");
	fflush(stdout);
	if (fgets(buf, sizeof(buf), stdin) == NULL) {
	    break;
	}
	buf[sizeof(buf) - 1u] = '\0';
	size_t len = strlen(buf);
	if ((len > 0) && (buf[len - 1] == '\n')) {
	    buf[len - 1] = '\0';
	    len--;
	}
	if ((len > 0) && (buf[len - 1] == '\r')) {
	    buf[len - 1] = '\0';
	    len--;
	}

	if (strcmp(buf, "exit") == 0L) {
	    break;
	} else {
	    printf("%s\n", buf);
	}
    }
    return 0L;
}
