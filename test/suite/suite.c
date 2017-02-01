#include "suite.h"

int tests_count = 0;

void print_header(char *title) {
    printf("\n\n%s\n\n", title);
    printf("%s\n\n", "Running all tests =)");

    tests_count = 0;
}

void print_footer() {
    printf("%s%d%s\n", "All ", tests_count, " tests finished");
}

void run_test(char *name, void (*function)(void)) {
    printf("%s: %s\n", "--> Running", name);
    (*function)();
    printf("%s: %s\n\n", "--> Finished", name);

    tests_count++;
}