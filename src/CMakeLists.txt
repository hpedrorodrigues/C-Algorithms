cmake_minimum_required(VERSION 2.8)

set(HEADER_FILES
        memory/memory.h
        data_structure/array_list/array_list.h
        data_structure/linked_list/singly/linked_list.h
        data_structure/linked_list/doubly/linked_list.h
        data_structure/queue/array/queue.h
        data_structure/queue/linked_list/queue.h
        data_structure/stack/array/stack.h
        data_structure/stack/linked_list/stack.h
        data_structure/hash_table/double_hashing/hash_table.h
        data_structure/hash_table/probing/linear/hash_table.h
        data_structure/hash_table/probing/quadratic/hash_table.h)

set(SOURCE_FILES
        memory/memory.c
        data_structure/array_list/array_list.c
        data_structure/linked_list/singly/linked_list.c
        data_structure/linked_list/doubly/linked_list.c
        data_structure/queue/array/queue.c
        data_structure/queue/linked_list/queue.c
        data_structure/stack/array/stack.c
        data_structure/stack/linked_list/stack.c
        data_structure/hash_table/double_hashing/hash_table.c
        data_structure/hash_table/probing/linear/hash_table.c
        data_structure/hash_table/probing/quadratic/hash_table.c)

set(CMAKE_BUILD_TYPE Release)

add_library(algorithms SHARED ${HEADER_FILES} ${SOURCE_FILES})