#ifndef SUITE_H
#define SUITE_H

#include <stdio.h>
#include <stdlib.h>

void print_header(char *title);

void run_test(char *name, void (*function)(void));

void print_footer();

#endif