cmake_minimum_required(VERSION 2.8)

set(HEADER_FILES
        util/util.h
        array_list/array_list.h
        linked_list/singly/singly_linked_list.h
        linked_list/doubly/doubly_linked_list.h
        queue/array/queue.h
        queue/linked_list/queue.h
        stack/array/stack.h
        stack/linked_list/stack.h)

set(SOURCE_FILES
        util/util.c
        array_list/array_list.c
        linked_list/singly/singly_linked_list.c
        linked_list/doubly/doubly_linked_list.c
        queue/array/queue.c
        queue/linked_list/queue.c
        stack/array/stack.c
        stack/linked_list/stack.c)

set(CMAKE_BUILD_TYPE Release)

add_library(algorithms SHARED ${HEADER_FILES} ${SOURCE_FILES})