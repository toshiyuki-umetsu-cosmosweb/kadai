#include <stdint.h>
#include <stdio.h>

int32_t
main(int32_t ac, char **av)
{
    if (ac > 1L) {
	printf("Hello %s\n", av[1]);
    } else {
	printf("Err: Argument not specified.\n");
    }
    return 0L;
}
