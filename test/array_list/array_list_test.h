#ifndef ARRAY_LIST_TEST_H
#define ARRAY_LIST_TEST_H

#include <assert.h>
#include "../suite/suite.h"
#include "array_list/array_list.h"

void run_all_array_list_tests();

void whenPushingValues_thenSizeMustBeIncreasedTest();

void whenChangingNumberOfElements_thenCapacityMayBeChangedTest();

void whenPopping_thenLastElementMayBeReturnedTest();

void whenRemovingAValue_thenAllOccurrencesMustBeDeletedTest();

void whenRemovingByAIndex_thenTheValuePlacedInThePositionMayBeDeletedTest();

void whenHasNoElements_thenIsEmptyMustBeReturnTrueTest();

void whenHasElements_thenIsEmptyMustBeReturnFalseTest();

void whenIndexIsBetweenZeroAndSizeMinusOne_thenIndexMayBeValidTest();

void whenIndexIsNotBetweenZeroAndSizeMinusOne_thenIndexMayBeNotValidTest();

void whenAValueExists_thenItMayBeFoundTest();

void whenAValueIsPrepended_thenOtherValuesMayBeShiftedTest();

#endif