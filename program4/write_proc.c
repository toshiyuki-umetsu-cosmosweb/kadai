#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "write_proc.h"

int32_t
write_proc(const char *output_file_path)
{
    int32_t retval;

    FILE *fp = fopen(output_file_path, "w");
    if (fp == NULL) {
	retval = errno;
	fprintf(stderr, "Could not open %s. (%s)\n",
		output_file_path, strerror(retval));
    } else {
	srand((unsigned int)(time(NULL)));
	for (int32_t i = 0L; i < 10L; i++) {
	    int32_t num = (int32_t)((rand() * 10L) / RAND_MAX);
	    fprintf(fp, "%d\n", num);
	}

	fclose(fp);
	retval = 0L;
    }
    return retval;
}
