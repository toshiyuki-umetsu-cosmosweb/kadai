#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int32_t operation_proc(double value1, const char *ope, double value2);

int32_t
main(int32_t ac, char **av)
{
    int32_t retval;

    if (ac != 4L) {
        fprintf(stderr, "Too few arguments.\n");
        fprintf(stderr, "usage:\n");
        fprintf(stderr, "  program3 value1# operation$ value2\n");
        retval = EXIT_FAILURE;
    } else {
        double value1 = strtod(av[1], NULL);
        double value2 = strtod(av[3], NULL);

        int32_t s = operation_proc(value1, av[2], value2);
        retval = (s == 0L) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    return retval;
}


static int32_t
operation_proc(double value1, const char *ope, double value2)
{
    int32_t retval = 0L;

    if (strlen(ope) == 1u) {
        switch (ope[0]) {
            case '+':
                printf("%lf\n", value1 + value2);
                break;
            case '-':
                printf("%lf\n", value1 - value2);
                break;
            case '*':
                printf("%lf\n", value1 * value2);
                break;
            case '/':
                if (value2 != 0.0) {
                    printf("%lf\n", value1 / value2);
                } else {
                    printf("Err: Divide by 0 occurred.\n");
                    retval = EINVAL;
                }
                break;
            default:
                fprintf(stderr, "Err: %s is not supported.\n", ope);
                retval = ENOTSUP;
                break;
        }
    } else {
        fprintf(stderr, "Err: %s is not supported.\n", ope);
        retval = EINVAL;
    }

    return retval;
}
