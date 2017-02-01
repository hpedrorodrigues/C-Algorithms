#include "suite.h"

const char *COLOR_GREEN = "\033[0;32m";
const char *COLOR_LIGHT_GREEN = "\033[1;32m";
const char *COLOR_RED = "\033[0;31m";
const char *COLOR_CYAN = "\033[0;36m";
const char *COLOR_WHITE = "\033[0m";
const char *COLOR_INTENSIVE_WHITE = "\033[1m";
const char *END_COLOR = "\033[0m";

int tests_count = 0;
char *test_name;

void catch(int signal, siginfo_t *si, void *arg) {
    printf("%s%s: %s\n\n%s", COLOR_RED, "--> Errored", test_name, END_COLOR);
    printf("%sSignal: %d\n%s", COLOR_RED, signal, END_COLOR);
    printf("%sArguments: %p\n%s", COLOR_RED, arg, END_COLOR);
    printf("%sCaught segmentation violation at address: %p\n%s", COLOR_RED, si->si_addr, END_COLOR);
    exit(0);
}

void try_run() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = catch;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGSEGV, &sa, NULL); /* segmentation violation */
}

void print_header(char *title) {
    printf("%s\n\n%s\n\n%s", COLOR_INTENSIVE_WHITE, title, END_COLOR);
    printf("%s%s\n\n%s", COLOR_WHITE, "Running all tests =)", END_COLOR);

    tests_count = 0;
    try_run();
}

void print_footer() {
    printf("%s%s%d%s\n%s", COLOR_LIGHT_GREEN, "All ", tests_count, " tests finished", END_COLOR);
}

void run_test(char *name, void (*function)(void)) {
    printf("%s%s: %s\n%s", COLOR_CYAN, "--> Running", name, END_COLOR);

    test_name = name;

    (*function)();

    printf("%s%s: %s\n\n%s", COLOR_GREEN, "--> Success", test_name, END_COLOR);

    tests_count++;
}