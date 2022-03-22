#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "read_input.h"

static int32_t get_random_int(int32_t max);
static void generate_random10(int32_t *data);
static int32_t get_input_number(void);
static bool check_proc(int32_t input, int32_t base);

int32_t
main(int32_t ac, char **av)
{
    int32_t ok_count = 0L;
    int32_t fail_count = 0L;

    srand(time(NULL));

    while (fail_count < 5L) {
	int32_t result_data[10u];
	int32_t data_count = 0L;

	if (data_count == 0L) {
	    generate_random10(result_data);
	    data_count = 10L;
	} 

	int32_t input_number = get_input_number();
	if (input_number < 0L) {
	    break;
	}

	if (check_proc(input_number, result_data[10 - data_count])) {
	    ok_count++;
	} else {
	    fail_count++;
	}
	data_count--;
    }
    printf("Total Score : %d\n", ok_count);

    return EXIT_SUCCESS;
}

/**
 * Generate random integer value of 0 to less than max.
 *
 * @param max Maximum value.
 * @return Return integer value.
 */
static int32_t
get_random_int(int32_t max)
{
    double d = ((double)(rand()) / (double)(RAND_MAX)) * (double)(max);
    return (int32_t)(d);
}

/**
 * Generate 0 to 9 numbers wich random order.
 *
 * @param data Buffer to store number. (Must larger than 10 members)
 */
static void
generate_random10(int32_t *data)
{
    int32_t num_array[10];
    int32_t data_count = 10L;

    for (int32_t i = 0L; i < data_count; i++) {
	num_array[i] = i;
    }

    int32_t store_count = 0L;
    while (data_count > 0L) {
	int32_t index = get_random_int(data_count);
	data[store_count] = num_array[index];
	while (index < data_count) {
	    num_array[index] = num_array[index + 1];
	    index++;
	}
	data_count--;
	store_count++;
    }

    return ;
}
/**
 * Getting input number.
 *
 * @return On success, return 0-9 number.
 *         Otherwise, return -1.
 */
static int32_t
get_input_number(void)
{
    char buf[256];

    while (true) {
	if (read_input("> ", buf, sizeof(buf)) <= 0L) {
	    return -1L;
	}
	int32_t input_number = strtol(buf, NULL, 0);
	if ((input_number >= 0L) && (input_number < 10L)) {
	    return input_number;
	}
    }
}

/**
 * Do number check.
 *
 * @param input Input number by user.
 * @param base Base number.
 * @return If result is pass, return true. Otherwise return false.
 */
static bool
check_proc(int32_t input, int32_t base)
{
    bool retval = false;

    if (base <= 4L) {
	if (input > base) {
	    printf("Good! %d>%d\n", input, base);
	    retval = true;
	} else {
	    printf("Oh no! %d\n", base);
	}
    } else {
	if (input < base) {
	    printf("Good! %d<%d\n", input, base);
	    retval = true;
	} else {
	    printf("Oh no! %d\n", base);
	}
    }

    return retval;
}
