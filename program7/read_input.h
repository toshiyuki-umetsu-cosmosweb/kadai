#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t read_input(const char *prompt, char *buf, size_t len);

#ifdef __cplusplus
}
#endif 
