cmake_minimum_required(VERSION 2.8)

set(SRC_DIR ../src)

include_directories(${SRC_DIR})

set(HEADER_FILES
        ${SRC_DIR}/memory/memory.h
        ${SRC_DIR}/data_structure/array_list/array_list.h
        ${SRC_DIR}/data_structure/linked_list/singly/singly_linked_list.h
        ${SRC_DIR}/data_structure/linked_list/doubly/doubly_linked_list.h
        ${SRC_DIR}/data_structure/queue/array/queue.h
        ${SRC_DIR}/data_structure/queue/linked_list/queue.h
        ${SRC_DIR}/data_structure/stack/array/stack.h
        ${SRC_DIR}/data_structure/stack/linked_list/stack.h)

set(SOURCE_FILES
        ${SRC_DIR}/memory/memory.c
        ${SRC_DIR}/data_structure/array_list/array_list.c
        ${SRC_DIR}/data_structure/linked_list/singly/singly_linked_list.c
        ${SRC_DIR}/data_structure/linked_list/doubly/doubly_linked_list.c
        ${SRC_DIR}/data_structure/queue/array/queue.c
        ${SRC_DIR}/data_structure/queue/linked_list/queue.c
        ${SRC_DIR}/data_structure/stack/array/stack.c
        ${SRC_DIR}/data_structure/stack/linked_list/stack.c)

set(TEST_HEADER_FILES
        suite/suite.h
        data_structure/array_list/array_list_test.h
        data_structure/linked_list/singly/linked_list_test.h
        data_structure/linked_list/doubly/linked_list_test.h
        data_structure/queue/array/queue_test.h
        data_structure/queue/linked_list/queue_test.h
        data_structure/stack/array/stack_test.h
        data_structure/stack/linked_list/stack_test.h)

set(TEST_SOURCE_FILES
        main.c
        suite/suite.c
        data_structure/array_list/array_list_test.c
        data_structure/linked_list/singly/linked_list_test.c
        data_structure/linked_list/doubly/linked_list_test.c
        data_structure/queue/array/queue_test.c
        data_structure/queue/linked_list/queue_test.c
        data_structure/stack/array/stack_test.c
        data_structure/stack/linked_list/stack_test.c)

add_executable(algorithms_test ${HEADER_FILES} ${SOURCE_FILES} ${TEST_HEADER_FILES} ${TEST_SOURCE_FILES})

enable_testing()