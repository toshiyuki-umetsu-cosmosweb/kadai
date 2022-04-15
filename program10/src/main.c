#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include <libgen.h>

struct wavegen_param {
    double voltage; // Voltage in V.
    double freq; // Frequence in Hz.
    const char *output_filename; // Output filename
};

static bool parse_wavegen_param(struct wavegen_param *param, int32_t argc, char **argv);
static int32_t wavegen_proc(const struct wavegen_param *param);

int32_t 
main(int32_t ac, char **av)
{
    int32_t retval;

    struct wavegen_param param;
    if (!parse_wavegen_param(&param, ac - 1L, av + 1L)) {
	fprintf(stderr, "Err: Argument not valid.\n");
	fprintf(stderr, "usage:\n");
	fprintf(stderr, "  %s voltage# freq# output-filename$\n", basename(av[0]));
	retval = EXIT_FAILURE;
    } else {
	int32_t status = wavegen_proc(&param);
	if (status == 0L) {
	    retval = EXIT_SUCCESS;
	} else {
	    fprintf(stderr, "%s\n", strerror(status));
	    retval = EXIT_FAILURE;
	}
    }

    return retval;
}
/**
 * Parse wave generator parameter.
 *
 * @param param A pointer to structore to store param.
 * @param argc Count of arguments.
 * @param argv Arguments 
 * @return On success, return true.
 *         If an error occurred, return false.
 */
static bool
parse_wavegen_param(struct wavegen_param *param, int32_t argc, char **argv)
{
    char *p;

    if (argc != 3L) {
	return false;
    }
    (*param).voltage = strtod(argv[0], &p);
    if ((p == NULL) || (*p != '\0')) {
	return false;
    }
    (*param).freq = strtod(argv[1], &p);
    if ((p == NULL) || (*p != '\0')) {
	return false;
    }
    (*param).output_filename = argv[2];

    return true;
}

/**
 * Generate Sin data.
 *
 * @param param Wave generate parameter.
 * @return On success, return 0.
 *         On error, an error number returned.
 */
static int32_t
wavegen_proc(const struct wavegen_param *param)
{
    int32_t retval;

    FILE *fp = fopen((*param).output_filename, "w");
    if (fp == NULL) {
	retval = errno;
    } else {
	double period_msec = 1000.0 / ((*param).freq * 2 * M_PI);

	// Print header.
	fprintf(fp, "msec[msec],voltage[V]\n");
	// Print data.
	for (int32_t msec = 0; msec < 4000L; msec++) {
	    double x = msec / period_msec;
	    double voltage = (*param).voltage * sin(x);
	    fprintf(fp, "%d,%lf,\n", msec, voltage); 
	}

	fclose(fp);
	retval = 0L;
    }

    return retval;

}
