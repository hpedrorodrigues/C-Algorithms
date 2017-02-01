#ifndef SINGLY_LINKED_LIST_TEST_H
#define SINGLY_LINKED_LIST_TEST_H

#include <assert.h>
#include "../../../suite/suite.h"
#include "data_structure/linked_list/singly/singly_linked_list.h"

void run_all_singly_linked_list_tests();

void sll_whenPrependAElement_thenItMustBeTheFirstElementTest();

void sll_whenAppendAElement_thenItMustBeTheLastElementTest();

void sll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest();

void sll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest();

void sll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest();

void sll_whenInsertingInAIndex_thenTheValueMustBeFoundTest();

void sll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest();

void sll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest();

void sll_whenReversingAList_thenAllElementsMustBeChangedTest();

#endif