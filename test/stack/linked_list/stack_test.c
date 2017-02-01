#include "stack_test.h"

void run_all_stack_linked_list_tests() {
    print_header("Stack - Linked List");

    run_test("whenPushingAElement_thenItMustBeTheLastElementTest",
             stll_whenPushingAElement_thenItMustBeTheLastElementTest);
    run_test("whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest",
             stll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest);

    print_footer();
}

void stll_whenPushingAElement_thenItMustBeTheLastElementTest() {
    StackLinkedList *stack = stll_new_instance();

    stll_push(stack, 1);
    stll_push(stack, 2);

    assert(stll_pop(stack) == 2);
    assert(stll_pop(stack) == 1);

    stll_destroy(stack);
}

void stll_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest() {
    StackLinkedList *stack = stll_new_instance();

    stll_push(stack, 1);

    assert(stll_pop(stack) == 1);

    stll_push(stack, 2);
    stll_push(stack, 3);

    assert(stll_pop(stack) == 3);
    assert(stll_pop(stack) == 2);

    stll_destroy(stack);
}