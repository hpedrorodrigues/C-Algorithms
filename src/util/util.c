#include "util.h"

void check_address(void *ptr) {
    if (ptr == NULL) {
        printf("%s\n", "Invalid pointer. Can't allocate memory.");
        exit(EXIT_FAILURE);
    }
}