#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../memory/memory.h"

#define nullptr 0
#define null -1

/**
 * Linked list node representation.
 */
struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
};

/**
 * Doubly linked list representation.
 */
typedef struct DoublyLinkedListImpl {
    struct DoublyLinkedListNode *head;
    struct DoublyLinkedListNode *tail;
} DoublyLinkedList;

/**
 * Creates a new {@link #DoublyLinkedListImpl DoublyLinkedList} instance.
 *
 * @return instance.
 */
DoublyLinkedList *dll_new_instance();

/**
 * Creates a new {@link #DoublyLinkedListNode Node} instance.
 *
 * @param value value of node
 * @return node
 */
struct DoublyLinkedListNode *dll_new_node(int value);

/**
 * Destroy the given {@link #DoublyLinkedListImpl DoublyLinkedList} instance.
 *
 * @param list instance to free memory
 */
void dll_destroy(DoublyLinkedList *list);

/**
 * Returns number of elements in the given list.
 *
 * @param list instance to evaluate
 * @return number of elements
 */
int dll_size(DoublyLinkedList *list);

/**
 * Verify if a given list has no elements.
 *
 * @param list instance to be evaluated
 * @return true if list is empty otherwise false
 */
bool dll_is_empty(DoublyLinkedList *list);

/**
 * Prepends the given value to the list, shifting trailing elements to the right.
 *
 * @param list instance to be evaluated
 * @param value value to insert
 */
void dll_prepend(DoublyLinkedList *list, int value);

/**
 * Append the given value to the list.
 *
 * @param list instance to be evaluated
 * @param value value to insert
 */
void dll_append(DoublyLinkedList *list, int value);

/**
 * Returns the value of first element in the list.
 *
 * @param list instance to be evaluated
 * @return first element data
 */
int dll_head(DoublyLinkedList *list);

/**
 * Returns the value of last element in the list.
 *
 * @param list instance to be evaluated
 * @return last element data
 */
int dll_tail(DoublyLinkedList *list);

/**
 * Returns the first element from the list and remove it.
 *
 * @param list instance to be evaluated
 * @return first element data
 */
int dll_pop_head(DoublyLinkedList *list);

/**
 * Returns the last element from the list and remove it.
 *
 * @param list instance to be evaluated
 * @return last element data
 */
int dll_pop(DoublyLinkedList *list);

/**
 * Inserts the given value at the given index.
 *
 * @param index index to be inserted
 * @param list instance to be evaluated
 * @param value value to insert
 */
void dll_insert_at(int index, DoublyLinkedList *list, int value);

/**
 * Returns the value stored at the given index.
 *
 * @param list instance to be evaluated
 * @param index index of element
 * @return value stored at the given index
 */
int dll_get_at(int index, DoublyLinkedList *list);

/**
 * Deletes the item stored at the given index.
 *
 * @param index index to be deleted
 * @param list instance to be evaluated
 */
void dll_remove_at(int index, DoublyLinkedList *list);

/**
 * Removes the given value from the array, even if it appears more than once.
 *
 * @param list instance to be evaluated
 * @param value value to be removed
 */
void dll_remove_value(DoublyLinkedList *list, int value);

/**
 * Reverse the values stored in the list in a new list.
 *
 * @param list instance to be evaluated
 */
DoublyLinkedList *dll_reverse(DoublyLinkedList *list);

/**
 * Verify if given index is valid or not.
 *
 * @param index index to verify
 * @param list instance to be evaluated
 * @return true if is valid otherwise false
 */
bool _dll_is_valid_index(int index, DoublyLinkedList *list);

/**
 * Prints public information about the list.
 * For debug purposes.
 *
 * @param list pointer to be evaluated
 */
void dll_print(DoublyLinkedList *list);

#endif