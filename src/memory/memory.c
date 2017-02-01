#include "memory.h"

void check_address(void *pointer) {
    if (pointer == NULL) {
        printf("%s\n", "Invalid pointer. Can't allocate memory.");
        exit(EXIT_FAILURE);
    }
}