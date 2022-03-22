#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static int32_t get_random_int(int32_t max);
static void generate_random10(int32_t *data);

int32_t
main(int32_t ac, char **av)
{
    int32_t result_data[10u];

    srand(time(NULL));
    generate_random10(result_data);
    for (int32_t i = 0L; i < 10L; i++) {
	printf("%d ", result_data[i]);
    }
    printf("\n");


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
