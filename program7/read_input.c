#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "read_input.h"

/**
 * Reading text from standard input.
 * A CR and LF are removed.
 *
 * @param prompt Prompt to display.
 * @param buf Buffer to store input text.
 * @param len Size of buf in bytes.
 * @return On success, return store text length returned..
 *         If terminated, return -1.
 */
int32_t
read_input(const char *prompt, char *buf, size_t len)
{
    int32_t retval = -1L;

    while (feof(stdin) == 0L) {
	fprintf(stdout, "%s", prompt);
	fflush(stdout);
	if (fgets(buf, len, stdin) != NULL) {
	    buf[len - 1u] = '\0';

	    len = strlen(buf);
	    if ((len > 0u) && (buf[len - 1u] == '\n')) {
		buf[len - 1u] = '\0';
		len--;
	    }
	    if ((len > 0u) && (buf[len - 1u] == '\r')) {
		buf[len - 1u] = '\0';
		len--;
	    }
	    if (len > 0u) {
		retval = (int32_t)(len);
		break;
	    }
	}
    }

    return retval;
}
