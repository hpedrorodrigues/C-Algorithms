#ifndef DOUBLY_LINKED_LIST_TEST_H
#define DOUBLY_LINKED_LIST_TEST_H

#include <assert.h>
#include "../../../suite/suite.h"
#include "data_structure/linked_list/doubly/doubly_linked_list.h"

void run_all_doubly_linked_list_tests();

void dll_whenPrependAElement_thenItMustBeTheFirstElementTest();

void dll_whenAppendAElement_thenItMustBeTheLastElementTest();

void dll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest();

void dll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest();

void dll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest();

void dll_whenInsertingInAIndex_thenTheValueMustBeFoundTest();

void dll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest();

void dll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest();

void dll_whenReversingAList_thenAllElementsMustBeChangedTest();

#endif