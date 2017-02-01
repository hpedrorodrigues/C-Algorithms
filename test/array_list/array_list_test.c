#include "array_list_test.h"

void run_all_array_list_tests() {
    print_header("Array");

    run_test("whenPushingValues_thenSizeMustBeIncreasedTest",
             whenPushingValues_thenSizeMustBeIncreasedTest);
    run_test("whenChangingNumberOfElements_thenCapacityMayBeChangedTest",
             whenChangingNumberOfElements_thenCapacityMayBeChangedTest);
    run_test("whenPopping_thenLastElementMayBeReturnedTest",
             whenPopping_thenLastElementMayBeReturnedTest);
    run_test("whenRemovingAValue_thenAllOccurrencesMustBeDeletedTest",
             whenRemovingAValue_thenAllOccurrencesMustBeDeletedTest);
    run_test("whenRemovingByAIndex_thenTheValuePlacedInThePositionMayBeDeletedTest",
             whenRemovingByAIndex_thenTheValuePlacedInThePositionMayBeDeletedTest);
    run_test("whenHasNoElements_thenIsEmptyMustBeReturnTrueTest",
             whenHasNoElements_thenIsEmptyMustBeReturnTrueTest);
    run_test("whenHasElements_thenIsEmptyMustBeReturnFalseTest",
             whenHasElements_thenIsEmptyMustBeReturnFalseTest);
    run_test("whenIndexIsBetweenZeroAndSizeMinusOne_thenIndexMayBeValidTest",
             whenIndexIsBetweenZeroAndSizeMinusOne_thenIndexMayBeValidTest);
    run_test("whenIndexIsNotBetweenZeroAndSizeMinusOne_thenIndexMayBeNotValidTest",
             whenIndexIsNotBetweenZeroAndSizeMinusOne_thenIndexMayBeNotValidTest);
    run_test("whenAValueExists_thenItMayBeFoundTest",
             whenAValueExists_thenItMayBeFoundTest);
    run_test("whenAValueIsPrepended_thenOtherValuesMayBeShiftedTest",
             whenAValueIsPrepended_thenOtherValuesMayBeShiftedTest);

    print_footer();
}

void whenPushingValues_thenSizeMustBeIncreasedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 3);
    al_push(array, 5);
    al_push(array, 7);

    assert(al_get_at(0, array) == 3);
    assert(al_get_at(1, array) == 5);
    assert(al_get_at(2, array) == 7);

    assert(al_size(array) == 3);
    assert(al_capacity(array) == 16);

    al_destroy(array);
}

void whenChangingNumberOfElements_thenCapacityMayBeChangedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    assert(al_capacity(array) == 16);

    // Forces a resize up
    for (register int i = 0; i < 18; ++i) {
        al_push(array, i + 1);
    }

    assert(al_capacity(array) == 32);

    // Forces a resize down
    for (register int i = 0; i < 15; ++i) {
        al_pop(array);
    }

    assert(al_capacity(array) == 16);

    al_destroy(array);
}

void whenPopping_thenLastElementMayBeReturnedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 1);
    al_push(array, 2);
    al_push(array, 3);
    al_push(array, 4);

    assert(al_pop(array) == 4);
    assert(al_pop(array) == 3);
    assert(al_pop(array) == 2);
    assert(al_pop(array) == 1);

    al_destroy(array);
}

void whenRemovingAValue_thenAllOccurrencesMustBeDeletedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 1);
    al_push(array, 2);
    al_push(array, 2);
    al_push(array, 3);

    assert(al_size(array) == 4);

    al_remove_value(array, 2);

    assert(al_size(array) == 2);
    assert(al_get_at(0, array) == 1);
    assert(al_get_at(1, array) == 3);

    al_destroy(array);
}

void whenRemovingByAIndex_thenTheValuePlacedInThePositionMayBeDeletedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 7);
    al_push(array, 6);
    al_push(array, 5);

    assert(al_size(array) == 3);
    assert(al_get_at(0, array) == 7);
    assert(al_get_at(1, array) == 6);
    assert(al_get_at(2, array) == 5);

    al_remove_at(1, array);

    assert(al_size(array) == 2);
    assert(al_get_at(0, array) == 7);
    assert(al_get_at(1, array) == 5);

    al_destroy(array);
}

void whenHasNoElements_thenIsEmptyMustBeReturnTrueTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    assert(al_is_empty(array));

    al_push(array, 1);
    al_pop(array);

    assert(al_is_empty(array));

    al_destroy(array);
}

void whenHasElements_thenIsEmptyMustBeReturnFalseTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 1);
    assert(!al_is_empty(array));

    al_destroy(array);
}

void whenIndexIsBetweenZeroAndSizeMinusOne_thenIndexMayBeValidTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 8);
    al_push(array, 9);
    al_push(array, 7);

    assert(_al_is_valid_index(0, array));
    assert(_al_is_valid_index(1, array));
    assert(_al_is_valid_index(2, array));

    al_destroy(array);
}

void whenIndexIsNotBetweenZeroAndSizeMinusOne_thenIndexMayBeNotValidTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 3);
    al_push(array, 2);

    assert(!_al_is_valid_index(-1, array));
    assert(!_al_is_valid_index(2, array));

    al_destroy(array);
}

void whenAValueExists_thenItMayBeFoundTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 1);
    al_push(array, 3);
    al_push(array, 5);
    al_push(array, 7);
    al_push(array, 7);

    assert(al_find(array, 1) == 0);
    assert(al_find(array, 3) == 1);
    assert(al_find(array, 5) == 2);
    assert(al_find(array, 7) == 3);
    assert(al_find(array, 7) == 3);

    al_destroy(array);
}

void whenAValueIsPrepended_thenOtherValuesMayBeShiftedTest() {
    ArrayList *array = al_new_instance(2 /* capacity */);

    al_push(array, 1);
    al_push(array, 2);
    al_push(array, 3);

    assert(al_get_at(0, array) == 1);
    assert(al_get_at(1, array) == 2);
    assert(al_get_at(2, array) == 3);

    al_prepend(array, 4);

    assert(al_get_at(0, array) == 4);
    assert(al_get_at(1, array) == 1);
    assert(al_get_at(2, array) == 2);
    assert(al_get_at(3, array) == 3);

    al_destroy(array);
}