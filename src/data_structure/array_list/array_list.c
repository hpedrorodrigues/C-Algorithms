#include "array_list.h"

const int AL_MinInitialCapacity = 1;
const int AL_MinCapacity = 16;
const int AL_GrowthFactor = 2;
const int AL_ShrinkFactor = 4;

ArrayList *al_new_instance(int capacity) {
    ArrayList *array = malloc(sizeof(ArrayList));
    int real_capacity = al_determine_capacity(capacity);

    check_address(array);

    array->size = 0;
    array->capacity = real_capacity;
    array->data = (int *) malloc(sizeof(int) * real_capacity);

    check_address(array->data);

    return array;
}

void al_destroy(ArrayList *array) {
    free(array->data);
    free(array);
}

void al_resize(ArrayList *array, int candidate_size) {
    if (array->size > candidate_size && array->size < array->capacity / AL_ShrinkFactor) {
        al_downsize(array);
    } else if (array->size < candidate_size && array->size == array->capacity) {
        al_upsize(array);
    } else {
        // Nothing to do
    }
}

int al_determine_capacity(int capacity) {
    if (capacity < AL_MinInitialCapacity) {
        return null;
    } else if (capacity < AL_MinCapacity) {
        return AL_MinCapacity;
    }

    int real_capacity = AL_MinInitialCapacity;
    while (capacity > real_capacity / AL_GrowthFactor) {
        real_capacity *= AL_GrowthFactor;
    }

    return real_capacity;
}

void al_upsize(ArrayList *array) {
    int old_capacity = array->capacity;
    int new_capacity = al_determine_capacity(old_capacity);
    int *new_data = (int *) malloc(sizeof(int) * new_capacity);

    check_address(new_data);

    for (register int i = 0; i < old_capacity; ++i) {
        *(new_data + i) = *(array->data + i);
    }

    free(array->data);

    array->data = new_data;
    array->capacity = new_capacity;
}

void al_downsize(ArrayList *array) {
    int old_capacity = array->capacity;
    int new_capacity = array->capacity / AL_GrowthFactor;

    if (new_capacity < AL_MinCapacity) {
        new_capacity = AL_MinCapacity;
    }

    if (new_capacity != old_capacity) {
        int *new_data = (int *) malloc(sizeof(int) * new_capacity);

        check_address(new_data);

        for (register int i = 0; i < array->size; ++i) {
            *(new_data + i) = *(array->data + i);
        }

        free(array->data);

        array->data = new_data;
        array->capacity = new_capacity;
    }
}

int al_size(ArrayList *array) {
    return array->size;
}

void al_push(ArrayList *array, int element) {
    al_resize(array, array->size + 1);

    *(array->data + array->size) = element;
    array->size++;
}

int al_capacity(ArrayList *array) {
    return array->capacity;
}

int al_get_at(int index, ArrayList *array) {
    if (!_al_is_valid_index(index, array)) {
        return null;
    }

    return *(array->data + index);
}

bool al_is_empty(ArrayList *array) {
    return array->size == 0;
}

bool _al_is_valid_index(int index, ArrayList *array) {
    return index >= 0 && index < array->size;
}

void al_insert(int index, ArrayList *array, int value) {
    if (!_al_is_valid_index(index, array)) {
        return;
    }

    al_resize(array, array->size + 1);

    int end_index = array->size - 1;
    for (register int i = end_index + 1; i > index; --i) {
        *(array->data + i) = *(array->data + i - 1);
    }

    *(array->data + index) = value;

    array->size += 1;
}

void al_prepend(ArrayList *array, int value) {
    al_insert(0, array, value);
}

int al_pop(ArrayList *array) {
    if (al_is_empty(array)) {
        return null;
    }

    al_resize(array, array->size - 1);

    int popped_value = *(array->data + array->size - 1);
    array->size--;

    return popped_value;
}

void al_remove_at(int index, ArrayList *array) {
    if (!_al_is_valid_index(index, array)) {
        return;
    }

    al_resize(array, array->size - 1);

    int end_index = array->size - 1;
    for (register int i = index; i < end_index; ++i) {
        *(array->data + i) = *(array->data + i + 1);
    }

    --(array->size);
}

void al_remove_value(ArrayList *array, int value) {
    for (register int i = 0; i < array->size; ++i) {
        int check_value = *(array->data + i);
        if (check_value == value) {
            al_remove_at(i, array);
            --i;
        }
    }
}

int al_find(ArrayList *array, int value) {
    int found_index = -1;

    for (register int i = 0; i < array->size; ++i) {
        if (*(array->data + i) == value) {
            found_index = i;
            break;
        }
    }

    return found_index;
}

void al_print(ArrayList *array) {
    printf("Size: %d\n", array->size);
    printf("Capacity: %d\n", array->capacity);
    printf("%s\n\n", "Items:");

    for (register int i = 0; i < array->size; ++i) {
        printf("%d) %d\n", i, *(array->data + i));
    }

    printf("---------\n\n");
}