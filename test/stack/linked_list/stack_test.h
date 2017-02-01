#ifndef STACK_LINKED_LIST_TEST_H
#define STACK_LINKED_LIST_TEST_H

#include <assert.h>
#include "../../suite/suite.h"
#include "stack/linked_list/stack.h"

void run_all_stack_linked_list_tests();

void stll_whenPushingAElement_thenItMustBeTheLastElementTest();

void stll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest();

#endif