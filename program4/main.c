#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_proc.h"

int32_t
main(int32_t ac, char **av)
{
    const char *output_file_path = "output.txt";
    int32_t retval;

    if (ac > 1L) {
	output_file_path = av[1];
    }

    if (write_proc(output_file_path) == 0L) {
	retval = EXIT_SUCCESS;
    } else {
	retval = EXIT_FAILURE;
    }

    return retval;
}
