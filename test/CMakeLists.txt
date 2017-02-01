cmake_minimum_required(VERSION 2.8)

set(SRC_DIR ../src)

include_directories(${SRC_DIR})

set(HEADER_FILES
        ${SRC_DIR}/util/util.h
        ${SRC_DIR}/array_list/array_list.h
        ${SRC_DIR}/linked_list/singly/singly_linked_list.h
        ${SRC_DIR}/linked_list/doubly/doubly_linked_list.h
        ${SRC_DIR}/queue/array/queue.h
        ${SRC_DIR}/queue/linked_list/queue.h
        ${SRC_DIR}/stack/array/stack.h
        ${SRC_DIR}/stack/linked_list/stack.h)

set(SOURCE_FILES
        ${SRC_DIR}/util/util.c
        ${SRC_DIR}/array_list/array_list.c
        ${SRC_DIR}/linked_list/singly/singly_linked_list.c
        ${SRC_DIR}/linked_list/doubly/doubly_linked_list.c
        ${SRC_DIR}/queue/array/queue.c
        ${SRC_DIR}/queue/linked_list/queue.c
        ${SRC_DIR}/stack/array/stack.c
        ${SRC_DIR}/stack/linked_list/stack.c)

set(TEST_HEADER_FILES
        suite/suite.h
        array_list/array_list_test.h
        linked_list/singly/linked_list_test.h
        linked_list/doubly/linked_list_test.h
        queue/array/queue_test.h
        queue/linked_list/queue_test.h
        stack/array/stack_test.h
        stack/linked_list/stack_test.h)

set(TEST_SOURCE_FILES
        main.c
        suite/suite.c
        array_list/array_list_test.c
        linked_list/singly/linked_list_test.c
        linked_list/doubly/linked_list_test.c
        queue/array/queue_test.c
        queue/linked_list/queue_test.c
        stack/array/stack_test.c
        stack/linked_list/stack_test.c suite/suite.h)

add_executable(algorithms_test ${HEADER_FILES} ${SOURCE_FILES} ${TEST_HEADER_FILES} ${TEST_SOURCE_FILES})

enable_testing()