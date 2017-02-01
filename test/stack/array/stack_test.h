#ifndef STACK_ARRAY_TEST_H
#define STACK_ARRAY_TEST_H

#include <assert.h>
#include "../../suite/suite.h"
#include "stack/array/stack.h"

void run_all_stack_array_tests();

void sa_whenPushingAElement_thenItMustBeTheLastElementTest();

void sa_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest();

#endif