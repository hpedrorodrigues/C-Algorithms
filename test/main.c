#include <stdlib.h>
#include "array_list/array_list_test.h"
#include "linked_list/singly/linked_list_test.h"
#include "linked_list/doubly/linked_list_test.h"
#include "queue/array/queue_test.h"
#include "queue/linked_list/queue_test.h"
#include "stack/array/stack_test.h"
#include "stack/linked_list/stack_test.h"

int main(int argc, char *argv[]) {

    run_all_array_list_tests();
    run_all_singly_linked_list_tests();
    run_all_doubly_linked_list_tests();
    run_all_queue_array_tests();
    run_all_queue_linked_list_tests();
    run_all_stack_array_tests();
    run_all_stack_linked_list_tests();

    return EXIT_SUCCESS;
}