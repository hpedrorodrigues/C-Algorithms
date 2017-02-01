#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../memory/memory.h"

#define nullptr 0
#define null -1

/**
 * Node of a stack representation.
 */
struct StackNode {
    int data;
    struct StackNode *next;
};

/**
 * Stack representation using a LinkedList.
 */
typedef struct StackLinkedListImpl {
    struct StackNode *head;
} StackLinkedList;

/**
 * Creates a new {@link #StackLinkedListImpl Stack} instance.
 *
 * @return instance
 */
StackLinkedList *stll_new_instance();

/**
 * Creates a new {@link #StackNode StackNode} instance.
 *
 * @param value value of node
 * @return node
 */
struct StackNode *stll_new_node(int value);

/**
 * Destroy the given {@link #StackLinkedListImpl Stack} instance.
 *
 * @param stack instance to free memory
 */
void stll_destroy(StackLinkedList *stack);

/**
 * Returns number of elements in the given stack.
 *
 * @param stack instance to evaluate
 * @return number of elements
 */
int stll_size(StackLinkedList *stack);

/**
 * Verify if a given stack has no elements.
 *
 * @param stack instance to be evaluated
 * @return true if stack is empty otherwise false
 */
bool stll_is_empty(StackLinkedList *stack);

/**
 * Push the given value to the stack.
 *
 * @param stack instance to be evaluated
 * @param value to insert
 */
void stll_push(StackLinkedList *stack, int value);

/**
 * Returns the last element from the stack and remove it.
 *
 * @param stack instance to be evaluated
 * @return last element data
 */
int stll_pop(StackLinkedList *stack);

/**
 * Prints public information about the stack for debug purposes.
 *
 * @param stack pointer to be evaluated
 */
void stll_print(StackLinkedList *stack);

#endif