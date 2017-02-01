#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../util/util.h"

#define null -1

/**
 * Stack representation using a Vector.
 */
typedef struct StackArrayImpl {
    int size;
    int capacity;
    int *data;
} StackArray;

/**
 * Creates a new {@link #StackArrayImpl Stack} instance to accommodate.
 *
 * @return instance
 */
StackArray *sa_new_instance();

/**
 * Destroy the given {@link #StackArrayImpl Stack} instance.
 *
 * @param stack pointer to destroy
 */
void sa_destroy(StackArray *stack);

/**
 * Resize the given {@link #StackArrayImpl stack} to support the candidate size.
 * The vector only is resized if is needed.
 *
 * @param stack pointer to resize
 * @param candidate_size size to support
 */
void sa_resize(StackArray *stack, int candidate_size);

/**
 * Determines the actual capacity, in terms of the power of growth factor, required to accommodate
 * a given capacity.
 *
 * @param capacity
 * @return
 */
int sa_al_determine_capacity(int capacity);

/**
 * Increases the stack size to size determined by growth factor.
 *
 * @param stack pointer to resize
 */
void sa_upsize(StackArray *stack);

/**
 * Decreases the stack size to size determined by growth factor.
 *
 * @param stack pointer to resize
 */
void sa_downsize(StackArray *stack);

/**
 * Verify if a given stack has no elements.
 *
 * @param stack instance to be evaluated
 * @return true if stack is empty otherwise false
 */
bool sa_is_empty(StackArray *stack);

/**
 * Returns the number of elements managed in the stack.
 *
 * @param stack pointer to evaluate
 * @return number of elements
 */
int sa_size(StackArray *stack);

/**
 * Push the given value to the stack.
 *
 * @param stack instance to be evaluated
 * @param value to insert
 */
void sa_push(StackArray *stack, int value);

/**
 * Returns the last element from the stack and remove it.
 *
 * @param stack instance to be evaluated
 * @return last element data
 */
int sa_pop(StackArray *stack);

/**
 * Prints public information about the stack for debug purposes.
 *
 * @param stack pointer to be evaluated
 */
void sa_print(StackArray *stack);

#endif