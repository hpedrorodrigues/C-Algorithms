#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../util/util.h"

#define nullptr 0
#define null -1

/**
 * Linked list node representation.
 */
struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode *next;
};

/**
 * Singly linked list representation.
 */
typedef struct SinglyLinkedListImpl {
    struct SinglyLinkedListNode *head;
    struct SinglyLinkedListNode *tail;
} SinglyLinkedList;

/**
 * Creates a new {@link #SinglyLinkedListImpl SinglyLinkedList} instance.
 *
 * @return instance.
 */
SinglyLinkedList *sll_new_instance();

/**
 * Creates a new {@link #SinglyLinkedListNode Node} instance.
 *
 * @param value value of node
 * @return node
 */
struct SinglyLinkedListNode *sll_new_node(int value);

/**
 * Destroy the given {@link #SinglyLinkedListImpl SinglyLinkedList} instance.
 *
 * @param list instance to free memory
 */
void sll_destroy(SinglyLinkedList *list);

/**
 * Returns number of elements in the given list.
 *
 * @param list instance to evaluate
 * @return number of elements
 */
int sll_size(SinglyLinkedList *list);

/**
 * Verify if a given list has no elements.
 *
 * @param list instance to be evaluated
 * @return true if list is empty otherwise false
 */
bool sll_is_empty(SinglyLinkedList *list);

/**
 * Prepends the given value to the list, shifting trailing elements to the right.
 *
 * @param list instance to be evaluated
 * @param value value to insert
 */
void sll_prepend(SinglyLinkedList *list, int value);

/**
 * Append the given value to the list.
 *
 * @param list instance to be evaluated
 * @param value value to insert
 */
void sll_append(SinglyLinkedList *list, int value);

/**
 * Returns the value of first element in the list.
 *
 * @param list instance to be evaluated
 * @return first element data
 */
int sll_head(SinglyLinkedList *list);

/**
 * Returns the value of last element in the list.
 *
 * @param list instance to be evaluated
 * @return last element data
 */
int sll_tail(SinglyLinkedList *list);

/**
 * Returns the first element from the list and remove it.
 *
 * @param list instance to be evaluated
 * @return first element data
 */
int sll_pop_head(SinglyLinkedList *list);

/**
 * Returns the last element from the list and remove it.
 *
 * @param list instance to be evaluated
 * @return last element data
 */
int sll_pop(SinglyLinkedList *list);

/**
 * Inserts the given value at the given index.
 *
 * @param index index to be inserted
 * @param list instance to be evaluated
 * @param value value to insert
 */
void sll_insert_at(int index, SinglyLinkedList *list, int value);

/**
 * Returns the value stored at the given index.
 *
 * @param list instance to be evaluated
 * @param index index of element
 * @return value stored at the given index
 */
int sll_get_at(int index, SinglyLinkedList *list);

/**
 * Deletes the item stored at the given index.
 *
 * @param index index to be deleted
 * @param list instance to be evaluated
 */
void sll_remove_at(int index, SinglyLinkedList *list);

/**
 * Removes the given value from the array, even if it appears more than once.
 *
 * @param list instance to be evaluated
 * @param value value to be removed
 */
void sll_remove_value(SinglyLinkedList *list, int value);

/**
 * Reverse the values stored in the list in a new list.
 *
 * @param list instance to be evaluated
 */
SinglyLinkedList *sll_reverse(SinglyLinkedList *list);

/**
 * Verify if given index is valid or not.
 *
 * @param index index to verify
 * @param list instance to be evaluated
 * @return true if is valid otherwise false
 */
bool _sll_is_valid_index(int index, SinglyLinkedList *list);

/**
 * Prints public information about the list.
 * For debug purposes.
 *
 * @param list pointer to be evaluated
 */
void sll_print(SinglyLinkedList *list);

#endif