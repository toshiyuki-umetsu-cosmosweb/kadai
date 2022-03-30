#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_input.h"

int32_t 
main(int32_t ac, char **av)
{
    int32_t retval;

    if (ac != 2L) {
        fprintf(stderr, "Err:Input file not specified.\n");
        retval = EXIT_FAILURE;
    } else {
        const char *input_filepath = av[1L];
        FILE *fp = fopen(input_filepath, "r");
        if (fp == NULL) {
            fprintf(stderr, "Err:Could not open input file.\n");
            retval = EXIT_FAILURE;
        } else {
            char buf[256];

            double sum = 0.0;
            int32_t count = 0;
            while (read_input(buf, sizeof(buf), fp) > 0L) {
                if (strlen(buf) > 32) {
                    fprintf(stderr, "Err:Too long line.\n");
                } else {
                    double d = strtod(buf, NULL);
                    printf("%s\n", buf);
                    sum += d;
                    count++;
                }
            }
            fclose(fp);
            if (count > 0L) {
                double average = sum / (double)(count);
                printf("Result: %f\n", average);
                retval = EXIT_SUCCESS;
            } else {
                fprintf(stderr, "Err: No data.\n");
                retval = EXIT_FAILURE;
            }
        }
    }

    return retval;
}

