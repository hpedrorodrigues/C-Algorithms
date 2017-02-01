#include "stack.h"

const int SA_MinInitialCapacity = 1;
const int SA_MinCapacity = 16;
const int SA_GrowthFactor = 2;
const int SA_ShrinkFactor = 4;

StackArray *sa_new_instance() {
    StackArray *stack = malloc(sizeof(StackArray));

    check_address(stack);

    stack->size = 0;
    stack->capacity = SA_MinCapacity;
    stack->data = (int *) malloc(sizeof(int) * SA_MinCapacity);

    check_address(stack->data);

    return stack;
}

void sa_destroy(StackArray *stack) {
    free(stack->data);
    free(stack);
}

void sa_resize(StackArray *stack, int candidate_size) {
    if (stack->size > candidate_size && stack->size < stack->capacity / SA_ShrinkFactor) {
        sa_downsize(stack);
    } else if (stack->size < candidate_size && stack->size == stack->capacity) {
        sa_upsize(stack);
    } else {
        // Nothing to do
    }
}

int sa_al_determine_capacity(int capacity) {
    if (capacity < SA_MinInitialCapacity) {
        return null;
    } else if (capacity < SA_MinCapacity) {
        return SA_MinCapacity;
    }

    int real_capacity = SA_MinInitialCapacity;
    while (capacity > real_capacity / SA_GrowthFactor) {
        real_capacity *= SA_GrowthFactor;
    }

    return real_capacity;
}

void sa_upsize(StackArray *stack) {
    int old_capacity = stack->capacity;
    int new_capacity = sa_al_determine_capacity(old_capacity);
    int *new_data = (int *) malloc(sizeof(int) * new_capacity);

    check_address(new_data);

    for (register int i = 0; i < old_capacity; ++i) {
        *(new_data + i) = *(stack->data + i);
    }

    free(stack->data);

    stack->data = new_data;
    stack->capacity = new_capacity;
}

void sa_downsize(StackArray *stack) {
    int old_capacity = stack->capacity;
    int new_capacity = stack->capacity / SA_GrowthFactor;

    if (new_capacity < SA_MinCapacity) {
        new_capacity = SA_MinCapacity;
    }

    if (new_capacity != old_capacity) {
        int *new_data = (int *) malloc(sizeof(int) * new_capacity);

        check_address(new_data);

        for (register int i = 0; i < stack->size; ++i) {
            *(new_data + i) = *(stack->data + i);
        }

        free(stack->data);

        stack->data = new_data;
        stack->capacity = new_capacity;
    }
}

bool sa_is_empty(StackArray *stack) {
    return stack->size == 0;
}

int sa_size(StackArray *stack) {
    return stack->size;
}

int capacity(StackArray *stack) {
    return stack->capacity;
}

void sa_push(StackArray *stack, int element) {
    sa_resize(stack, stack->size + 1);

    *(stack->data + stack->size) = element;
    ++(stack->size);
}

int sa_pop(StackArray *stack) {
    if (sa_is_empty(stack)) {
        return null;
    }

    sa_resize(stack, stack->size - 1);

    int popped_value = *(stack->data + stack->size - 1);
    stack->size--;

    return popped_value;
}

void sa_print(StackArray *stack) {
    printf("Size: %d\n", stack->size);
    printf("Capacity: %d\n", stack->capacity);
    printf("%s\n\n", "Items:");

    for (register int i = 0; i < stack->size; ++i) {
        printf("%d) %d\n", i, *(stack->data + i));
    }

    printf("---------\n\n");
}