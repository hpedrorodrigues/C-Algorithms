#include "stack_test.h"

void run_all_stack_array_tests() {
    print_header("Stack - Array");

    run_test("whenPushingAElement_thenItMustBeTheLastElementTest",
             sa_whenPushingAElement_thenItMustBeTheLastElementTest);
    run_test("whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest",
             sa_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest);

    print_footer();
}

void sa_whenPushingAElement_thenItMustBeTheLastElementTest() {
    StackArray *stack = sa_new_instance();

    sa_push(stack, 1);
    sa_push(stack, 2);

    assert(sa_pop(stack) == 2);
    assert(sa_pop(stack) == 1);

    sa_destroy(stack);
}

void sa_whenPopping_thenTheLastElementMustBeReturnedAndDeletedTest() {
    StackArray *stack = sa_new_instance();

    sa_push(stack, 1);

    assert(sa_pop(stack) == 1);

    sa_push(stack, 2);
    sa_push(stack, 3);

    assert(sa_pop(stack) == 3);
    assert(sa_pop(stack) == 2);

    sa_destroy(stack);
}