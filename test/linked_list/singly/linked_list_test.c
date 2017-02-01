#include "linked_list_test.h"

void run_all_singly_linked_list_tests() {
    print_header("Singly Linked List");

    run_test("whenPrependAElement_thenItMustBeTheFirstElementTest",
             sll_whenPrependAElement_thenItMustBeTheFirstElementTest);
    run_test("whenAppendAElement_thenItMustBeTheLastElementTest",
             sll_whenAppendAElement_thenItMustBeTheLastElementTest);
    run_test("whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest",
             sll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest);
    run_test("whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest",
             sll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest);
    run_test("whenAppendMultipleElements_thenTheyMustBeVerifiedTest",
             sll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest);
    run_test("whenInsertingInAIndex_thenTheValueMustBeFoundTest",
             sll_whenInsertingInAIndex_thenTheValueMustBeFoundTest);
    run_test("whenRemovingByAIndex_thenTheValueMustBeDeletedTest",
             sll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest);
    run_test("whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest",
             sll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest);
    run_test("whenReversingAList_thenAllElementsMustBeChangedTest",
             sll_whenReversingAList_thenAllElementsMustBeChangedTest);

    print_footer();
}

void sll_whenPrependAElement_thenItMustBeTheFirstElementTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_prepend(list, 10);
    assert(sll_size(list) == 1);
    assert(sll_head(list) == 10);

    sll_prepend(list, 20);
    assert(sll_size(list) == 2);
    assert(sll_head(list) == 20);
    assert(sll_tail(list) == 10);

    sll_destroy(list);
}

void sll_whenAppendAElement_thenItMustBeTheLastElementTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_prepend(list, 5);
    sll_append(list, 7);

    assert(sll_size(list) == 2);
    assert(sll_head(list) == 5);
    assert(sll_tail(list) == 7);

    sll_append(list, 9);

    assert(sll_size(list) == 3);
    assert(sll_head(list) == 5);
    assert(sll_tail(list) == 9);

    sll_destroy(list);
}

void sll_whenPoppingHead_thenTheFirstElementMustBeReturnedAndDeletedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 1);
    sll_append(list, 2);

    assert(sll_size(list) == 2);

    assert(sll_pop_head(list) == 1);
    assert(sll_pop_head(list) == 2);

    assert(sll_is_empty(list));

    sll_destroy(list);
}

void sll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 4);
    sll_append(list, 5);

    assert(sll_size(list) == 2);

    assert(sll_pop(list) == 5);
    assert(sll_pop(list) == 4);

    assert(sll_is_empty(list));

    sll_destroy(list);
}

void sll_whenAppendMultipleElements_thenTheyMustBeVerifiedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 2);
    sll_append(list, 3);
    sll_append(list, 4);

    assert(sll_get_at(0, list) == 2);
    assert(sll_get_at(1, list) == 3);
    assert(sll_get_at(2, list) == 4);

    sll_destroy(list);
}

void sll_whenInsertingInAIndex_thenTheValueMustBeFoundTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 1);
    sll_append(list, 4);

    sll_insert_at(1, list, 2);

    assert(sll_size(list) == 3);
    assert(sll_get_at(0, list) == 1);
    assert(sll_get_at(1, list) == 2);
    assert(sll_get_at(2, list) == 4);

    sll_insert_at(2, list, 3);

    assert(sll_size(list) == 4);
    assert(sll_get_at(0, list) == 1);
    assert(sll_get_at(1, list) == 2);
    assert(sll_get_at(2, list) == 3);
    assert(sll_get_at(3, list) == 4);

    sll_destroy(list);
}

void sll_whenRemovingByAIndex_thenTheValueMustBeDeletedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 1);
    sll_remove_at(0, list);
    assert(sll_is_empty(list));

    sll_append(list, 2);
    sll_append(list, 3);
    sll_remove_at(1, list);

    assert(sll_size(list) == 1);

    assert(sll_head(list) == 2);
    assert(sll_tail(list) == 2);

    sll_remove_at(0, list);

    assert(sll_is_empty(list));

    sll_destroy(list);
}

void sll_whenRemovingByAValue_thenAllOccurrencesMustBeDeletedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 2);
    sll_append(list, 2);
    sll_append(list, 3);
    sll_append(list, 4);

    sll_remove_value(list, 2);

    assert(sll_size(list) == 2);
    assert(sll_head(list) == 3);
    assert(sll_tail(list) == 4);

    sll_remove_value(list, 3);

    assert(sll_size(list) == 1);
    assert(sll_head(list) == 4);
    assert(sll_tail(list) == 4);

    sll_remove_value(list, 4);

    assert(sll_is_empty(list));

    sll_destroy(list);
}

void sll_whenReversingAList_thenAllElementsMustBeChangedTest() {
    SinglyLinkedList *list = sll_new_instance();

    sll_append(list, 1);
    sll_append(list, 2);
    sll_append(list, 3);

    SinglyLinkedList *reversed = sll_reverse(list);

    assert(sll_size(reversed) == 3);
    assert(sll_get_at(0, reversed) == 3);
    assert(sll_get_at(1, reversed) == 2);
    assert(sll_get_at(2, reversed) == 1);

    sll_destroy(list);
    sll_destroy(reversed);
}