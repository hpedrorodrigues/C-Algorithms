#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../memory/memory.h"

#define nullptr 0

/**
 * Node of a queue representation.
 */
struct QueueNode {
    int data;
    struct QueueNode *next;
};

/**
 * Queue representation using a LinkedList.
 */
typedef struct QueueLinkedListImpl {
    struct QueueNode *head;
    struct QueueNode *tail;
} QueueLinkedList;

/**
 * Creates a new {@link #QueueLinkedListImpl Queue} instance.
 *
 * @return instance
 */
QueueLinkedList *qll_new_instance();

/**
 * Creates a new {@link #QueueNode Node} instance.
 *
 * @param value value of node
 * @return node
 */
struct QueueNode *qll_new_node(int value);

/**
 * Destroy the given {@link #QueueLinkedListImpl Queue} instance.
 *
 * @param queue instance to free memory
 */
void qll_destroy(QueueLinkedList *queue);

/**
 * Returns number of elements in the given queue.
 *
 * @param queue instance to evaluate
 * @return number of elements
 */
int qll_size(QueueLinkedList *queue);

/**
 * Verify if a given queue has no elements.
 *
 * @param queue instance to be evaluated
 * @return true if queue is empty otherwise false
 */
bool _qll_is_empty(QueueLinkedList *queue);

/**
 * Inserts the specified value into this queue.
 *
 * @param queue instance to be evaluated
 * @param value value to insert
 */
void qll_enqueue(QueueLinkedList *queue, int value);

/**
 * Retrieves and removes the head of this queue.
 *
 * @param queue instance to be evaluated
 * @return first element data
 */
int qll_dequeue(QueueLinkedList *queue);

/**
 * Prints public information about the queue for debug purposes.
 *
 * @param queue pointer to be evaluated
 */
void qll_print(QueueLinkedList *queue);

#endif