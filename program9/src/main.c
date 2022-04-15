#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <libgen.h>

static int32_t main_proc(const char* file_path);
static int32_t split_line(char *line, char **tokens, int32_t max_tokens, const char *delim);

int32_t
main(int32_t ac, char **av)
{
    int32_t status;

    if (ac != 2) {
	printf("usage:\n");
	printf("  %s data-file$\n", basename(av[0]));
	status = EXIT_FAILURE;
    } else {
	int32_t retval = main_proc(av[1]);
	if (retval == 0L) {
	    status = EXIT_SUCCESS;
	} else {
	    fprintf(stderr, "%s\n", strerror(retval));
	    status = EXIT_FAILURE;
	}
    }

    return status;
}
/**
 * Reading file_path, print column 1 and 3. After that, print average.
 *
 * @param file_path File path.
 */
static int32_t
main_proc(const char* file_path)
{
    int32_t retval;

    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
	retval = errno;
    } else {
	double sum = 0.0;
	char buf[256];
	while (fgets(buf, sizeof(buf), fp) != NULL) {
	    char *tokens[32];
	    int token_count = split_line(buf, tokens, (int32_t)(sizeof(tokens) / sizeof(char*)), ",");
	    if (token_count < 3L) {
		continue;
	    }

	    const char *name = tokens[0];
	    char *ptr;
	    const double voltage = strtod(tokens[2], &ptr);
	    if ((ptr != NULL) && (*ptr == '\0')) {
		printf("%s = %.2lf\n", name, voltage);
		sum += voltage;
	    }
	}
	fclose(fp);

	printf("Total = %.2lf\n", sum);

	retval = 0L;
    }

    return retval;
}
/**
 * Split line by specified delimiters.
 *
 * @param line Line
 * @param tokens Pointer list to store tokens.
 * @param max_tokens Maximum split count.
 * @param delim Delimiter.
 * @return On success, return token count.
 *         On error, return -1 with set the errno.
 */
static int32_t
split_line(char *line, char **tokens, int32_t max_tokens, const char *delim)
{
    int32_t n = 0;

    // Note : This function is static, so you can omit checking arguments for performance.
    //        Because passing arguments are known.
    if ((line == NULL) || (tokens == NULL) || (max_tokens <= 0) || (delim == NULL)) {
	errno = EINVAL;
	return -1;
    }

    char *ptr = line;
    while (n < (max_tokens - 1L)) {
	char *token = strtok_r(NULL, delim, &ptr);
	if (token != NULL) {
	    tokens[n] = token;
	    n++;
	} else {
	    break;
	}
    }
    if (n < max_tokens) {
	tokens[n] = NULL;
    }

    return n;
}

