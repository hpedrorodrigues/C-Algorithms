#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../util/util.h"

#define null -1

/**
 * Automatically resizing vector representation.
 */
typedef struct ArrayListImpl {
    int size;
    int capacity;
    int *data;
} ArrayList;

/**
 * Creates a new {@link #ArrayListImpl Array} instance to accommodate.
 *
 * @param capacity the given initial capacity
 * @return instance
 */
ArrayList *al_new_instance(int capacity);

/**
 * Destroy the given {@link #ArrayListImpl Array} instance.
 *
 * @param array pointer to destroy
 */
void al_destroy(ArrayList *array);

/**
 * Resize the given {@link #ArrayListImpl Array} to support the candidate size.
 * The vector only is resized if is needed.
 *
 * @param array pointer to resize
 * @param candidate_size size to support
 */
void al_resize(ArrayList *array, int candidate_size);

/**
 * Determines the actual capacity, in terms of the power of growth factor, required to accommodate
 * a given capacity.
 *
 * @param capacity
 * @return
 */
int al_determine_capacity(int capacity);

/**
 * Increases the array size to size determined by growth factor.
 *
 * @param array pointer to resize
 */
void al_upsize(ArrayList *array);

/**
 * Decreases the array size to size determined by growth factor.
 *
 * @param array pointer to resize
 */
void al_downsize(ArrayList *array);

/**
 * Returns the number of elements managed in the array.
 *
 * @param array pointer to evaluate
 * @return number of elements
 */
int al_size(ArrayList *array);

/**
 * Appends the given element to the end of the array.
 *
 * @param array pointer to append
 * @param element element to be appended
 */
void al_push(ArrayList *array, int element);

/**
 * Returns the current capacity the array can accommodate.
 *
 * @param array pointer to be evaluated
 * @return capacity number of elements that array can accommodate
 */
int al_capacity(ArrayList *array);

/**
 * Returns the value stored at the given index.
 *
 * @param array pointer to be evaluated
 * @param index index of element
 * @return value stored at the given index
 */
int al_get_at(int index, ArrayList *array);

/**
 * Verify if a given array has no elements.
 *
 * @param array pointer to be evaluated
 * @return true if array is empty otherwise false
 */
bool al_is_empty(ArrayList *array);

/**
 * Verify if a given index is in array limits.
 *
 * @param array pointer to be evaluated
 * @return true if array is empty otherwise false
 */
bool _al_is_valid_index(int index, ArrayList *array);

/**
 * Inserts the given value at the given index, shifting current and trailing elements to the right.
 *
 * @param index index to be inserted
 * @param array pointer to be evaluated
 * @param value value to insert
 */
void al_insert(int index, ArrayList *array, int value);

/**
 * Prepends the given value to the array, shifting trailing elements to the right.
 *
 * @param array pointer to be evaluated
 * @param value value to insert
 */
void al_prepend(ArrayList *array, int value);

/**
 * Removes the last item from the array and returns its value.
 *
 * @param array pointer to be evaluated
 * @return removed element
 */
int al_pop(ArrayList *array);

/**
 * Deletes the item stored at the given index, shifting trailing elements to the left.
 *
 * @param index index to be deleted
 * @param array pointer to be evaluated
 */
void al_remove_at(int index, ArrayList *array);

/**
 * Removes the given value from the array, even if it appears more than once.
 *
 * @param array pointer to be evaluated
 * @param value value to be removed
 */
void al_remove_value(ArrayList *array, int value);

/**
 * Returns the index of the first occurrence of the given value in the array, if it is not present
 * then -1 is returned.
 *
 * @param array pointer to be evaluated
 * @param value value to search
 * @return index of the first occurrence or -1 if it is not present
 */
int al_find(ArrayList *array, int value);

/**
 * Prints public information about the array.
 * For debug purposes.
 *
 * @param array pointer to be evaluated
 */
void al_print(ArrayList *array);

#endif