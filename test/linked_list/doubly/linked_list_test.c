#include "linked_list_test.h"

void run_all_doubly_linked_list_tests() {
    print_header("Doubly Linked List");

    run_test("whenPrependAElement_thenItMustBeTheFirstElementTest",
             dll_whenPrependAElement_thenItMustBeTheFirstElementTest);
    run_test("whenAppendAElement_thenItMustBeTheLastElementTest",
             dll_whenAppendAElement_thenItMustBeTheLastElementTest);
    run_test("whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest",
             dll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest);
    run_test("whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest",
             dll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest);
    run_test("whenAppendMultipleElements_thenTheyMustBeVerifiedTest",
             dll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest);
    run_test("whenInsertingInAIndex_thenTheValueMustBeFoundTest",
             dll_whenInsertingInAIndex_thenTheValueMustBeFoundTest);
    run_test("whenRemovingByAIndex_thenTheValueMustBeDeletedTest",
             dll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest);
    run_test("whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest",
             dll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest);
    run_test("whenReversingAList_thenAllElementsMustBeChangedTest",
             dll_whenReversingAList_thenAllElementsMustBeChangedTest);

    print_footer();
}

void dll_whenPrependAElement_thenItMustBeTheFirstElementTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_prepend(list, 10);
    assert(dll_size(list) == 1);
    assert(dll_head(list) == 10);

    dll_prepend(list, 20);
    assert(dll_size(list) == 2);
    assert(dll_head(list) == 20);
    assert(dll_tail(list) == 10);

    dll_destroy(list);
}

void dll_whenAppendAElement_thenItMustBeTheLastElementTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_prepend(list, 5);
    dll_append(list, 7);

    assert(dll_size(list) == 2);
    assert(dll_head(list) == 5);
    assert(dll_tail(list) == 7);

    dll_append(list, 9);

    assert(dll_size(list) == 3);
    assert(dll_head(list) == 5);
    assert(dll_tail(list) == 9);

    dll_destroy(list);
}

void dll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 1);
    dll_append(list, 2);

    assert(dll_size(list) == 2);

    assert(dll_pop_head(list) == 1);
    assert(dll_pop_head(list) == 2);

    assert(dll_is_empty(list));

    dll_destroy(list);
}

void dll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 4);
    dll_append(list, 5);

    assert(dll_size(list) == 2);

    assert(dll_pop(list) == 5);
    assert(dll_pop(list) == 4);

    assert(dll_is_empty(list));

    dll_destroy(list);
}

void dll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 2);
    dll_append(list, 3);
    dll_append(list, 4);

    assert(dll_get_at(0, list) == 2);
    assert(dll_get_at(1, list) == 3);
    assert(dll_get_at(2, list) == 4);

    dll_destroy(list);
}

void dll_whenInsertingInAIndex_thenTheValueMustBeFoundTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 1);
    dll_append(list, 4);

    dll_insert_at(1, list, 2);

    assert(dll_size(list) == 3);
    assert(dll_get_at(0, list) == 1);
    assert(dll_get_at(1, list) == 2);
    assert(dll_get_at(2, list) == 4);

    dll_insert_at(2, list, 3);

    assert(dll_size(list) == 4);
    assert(dll_get_at(0, list) == 1);
    assert(dll_get_at(1, list) == 2);
    assert(dll_get_at(2, list) == 3);
    assert(dll_get_at(3, list) == 4);

    dll_destroy(list);
}

void dll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 1);
    dll_remove_at(0, list);
    assert(dll_is_empty(list));

    dll_append(list, 2);
    dll_append(list, 3);
    dll_remove_at(1, list);

    assert(dll_size(list) == 1);

    assert(dll_head(list) == 2);
    assert(dll_tail(list) == 2);

    dll_remove_at(0, list);

    assert(dll_is_empty(list));

    dll_destroy(list);
}

void dll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 2);
    dll_append(list, 2);
    dll_append(list, 3);
    dll_append(list, 4);

    dll_remove_value(list, 2);

    assert(dll_size(list) == 2);
    assert(dll_head(list) == 3);
    assert(dll_tail(list) == 4);

    dll_remove_value(list, 3);

    assert(dll_size(list) == 1);
    assert(dll_head(list) == 4);
    assert(dll_tail(list) == 4);

    dll_remove_value(list, 4);

    assert(dll_is_empty(list));

    dll_destroy(list);
}

void dll_whenReversingAList_thenAllElementsMustBeChangedTest() {
    DoublyLinkedList *list = dll_new_instance();

    dll_append(list, 1);
    dll_append(list, 2);
    dll_append(list, 3);

    DoublyLinkedList *reversed = dll_reverse(list);

    assert(dll_size(reversed) == 3);
    assert(dll_get_at(0, reversed) == 3);
    assert(dll_get_at(1, reversed) == 2);
    assert(dll_get_at(2, reversed) == 1);

    dll_destroy(list);
    dll_destroy(reversed);
}