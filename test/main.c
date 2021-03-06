#include <stdlib.h>
#include "data_structure/array_list/array_list_test.h"
#include "data_structure/linked_list/singly/linked_list_test.h"
#include "data_structure/linked_list/doubly/linked_list_test.h"
#include "data_structure/queue/array/queue_test.h"
#include "data_structure/queue/linked_list/queue_test.h"
#include "data_structure/stack/array/stack_test.h"
#include "data_structure/stack/linked_list/stack_test.h"
#include "data_structure/hash_table/double_hashing/hash_table_test.h"
#include "data_structure/hash_table/probing/linear/hash_table_test.h"
#include "data_structure/hash_table/probing/quadratic/hash_table_test.h"

int main(int argc, char *argv[]) {

    run_all_array_list_tests();
    run_all_singly_linked_list_tests();
    run_all_doubly_linked_list_tests();
    run_all_queue_array_tests();
    run_all_queue_linked_list_tests();
    run_all_stack_array_tests();
    run_all_stack_linked_list_tests();
    run_all_hash_table_double_hashing_tests();
    run_all_hash_table_linear_probing_tests();
    run_all_hash_table_quadratic_probing_tests();

    return EXIT_SUCCESS;
}