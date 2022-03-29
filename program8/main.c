#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_ARGS (20u)

static int32_t numcmp(const void *val1, const void *val2);
static bool parse_arguments(int32_t ac, char **av, int32_t *data_array);
static void print_result(int32_t *data_array, int32_t data_count,
	double elapse_millis);

int32_t
main(int32_t ac, char **av)
{
    int32_t retval;
    int32_t data_array[MAX_ARGS];

    if (ac > (MAX_ARGS + 1)) {
	fprintf(stderr, "Err:Too meny arguments.\n");
	retval = EXIT_FAILURE;
    } else {
	int32_t data_count = ac - 1L;
	if (parse_arguments(data_count, av + 1u, data_array)) {
	    struct timespec begin, end;
	    clock_gettime(CLOCK_MONOTONIC, &begin);

	    qsort(data_array, data_count, sizeof(int32_t), numcmp);

	    clock_gettime(CLOCK_MONOTONIC, &end);
	    double elapse_msec
		    = (double)(end.tv_sec - begin.tv_sec) * 1000.0
		    + (double)(end.tv_nsec - begin.tv_nsec) / 1000000.0;
	    print_result(data_array, data_count, elapse_msec);

	    retval = EXIT_SUCCESS;
	} else {
	    retval = EXIT_FAILURE;
	}
    }
    return retval;
}

/**
 * Parse arguments and store data.
 *
 * @param ac Count of arguments which removed first argument.
 * @param av Arguments which removed first argument.
 * @param data_array Array to store data.
 * @return On success, return true, otherwise, return false.
 */
static bool
parse_arguments(int32_t ac, char **av, int32_t *data_array)
{
    int32_t i = 0L;

    while (i < ac) {
	char *ptr = NULL;
	data_array[i] = strtol(av[i], &ptr, 0);
	if ((ptr == NULL) || (*ptr != '\0')) {
	    fprintf(stderr, "Err:Invalid argument. : %s\n", av[i]);
	    break;
	}

	i++;
    }

    return (i == ac);
}
/**
 * Compare number to use qsort.
 *
 * @param val1 Pointer of value1.
 * @param val2 Pointer of value2
 * @return If val1 is less than value2, return negative integer.
 *         If val1 is more than value2, return positive integer.
 *         Otherwise, return 0.
 */
static int32_t
numcmp(const void *val1, const void *val2)
{
    return *((int32_t*)(val1)) - *((int32_t*)(val2));
}

/**
 * Print result.
 *
 * @param data_array Data array of results.
 * @param data_count Count of data.
 * @param elapse_millis Elapse time in milli seconds.
 */
static void
print_result(int32_t *data_array, int32_t data_count,
	double elapse_millis)
{
    for (int32_t i = 0L; i < data_count; i++) {
	printf("%d ", data_array[i]);
    }
    printf("\n");
    printf("Elase : %.3lf[msec]\n", elapse_millis);

    return ;
}
