#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../util/util.h"

#define null -1

/**
 * Queue representation using a Vector.
 */
typedef struct QueueArrayImpl {
    int size;
    int capacity;
    int *data;
} QueueArray;

/**
 * Creates a new {@link #QueueArrayImpl Queue} instance to accommodate.
 *
 * @return instance
 */
QueueArray *qa_new_instance();

/**
 * Destroy the given {@link #QueueArrayImpl Queue} instance.
 *
 * @param queue pointer to destroy
 */
void qa_destroy(QueueArray *queue);

/**
 * Resize the given {@link #QueueArrayImpl Queue} to support the candidate size.
 * The vector only is resized if is needed.
 *
 * @param queue pointer to resize
 * @param candidate_size size to support
 */
void qa_resize(QueueArray *queue, int candidate_size);

/**
 * Determines the actual capacity, in terms of the power of growth factor, required to accommodate
 * a given capacity.
 *
 * @param capacity
 * @return
 */
int qa_determine_capacity(int capacity);

/**
 * Increases the queue size to size determined by growth factor.
 *
 * @param queue pointer to resize
 */
void qa_upsize(QueueArray *queue);

/**
 * Decreases the queue size to size determined by growth factor.
 *
 * @param queue pointer to resize
 */
void qa_downsize(QueueArray *queue);

/**
 * Returns the number of elements managed in the queue.
 *
 * @param queue pointer to evaluate
 * @return number of elements
 */
int qa_size(QueueArray *queue);

/**
 * Verify if a given queue has no elements.
 *
 * @param queue pointer to be evaluated
 * @return true if queue is empty otherwise false
 */
bool _qa_is_empty(QueueArray *queue);

/**
 * Inserts the specified value into this queue.
 *
 * @param queue instance to be evaluated
 * @param value value to insert
 */
void qa_enqueue(QueueArray *queue, int value);

/**
 * Retrieves and removes the head of this queue.
 *
 * @param queue instance to be evaluated
 * @return first element data
 */
int qa_dequeue(QueueArray *queue);

/**
 * Prints public information about the queue for debug purposes.
 *
 * @param queue pointer to be evaluated
 */
void qa_print(QueueArray *queue);

#endif