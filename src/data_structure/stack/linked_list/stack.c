#include "stack.h"

StackLinkedList *stll_new_instance() {
    StackLinkedList *stack = malloc(sizeof(StackLinkedList));

    check_address(stack);

    stack->head = nullptr;

    return stack;
}

struct StackNode *stll_new_node(int value) {
    struct StackNode *node = malloc(sizeof(struct StackNode));

    check_address(node);

    node->next = nullptr;
    node->data = value;

    return node;
}

void stll_destroy(StackLinkedList *stack) {
    struct StackNode *current = stack->head;
    struct StackNode *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}

int stll_size(StackLinkedList *stack) {
    struct StackNode *current = stack->head;
    int size = 0;

    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
}

bool stll_is_empty(StackLinkedList *stack) {
    return stack->head == nullptr;
}

void stll_push(StackLinkedList *stack, int value) {
    struct StackNode *node = stll_new_node(value);

    node->next = stack->head;
    stack->head = node;
}

int stll_pop(StackLinkedList *stack) {
    if (stll_is_empty(stack)) {
        printf("StackLinkedList is empty.\n");
        return null;
    }

    struct StackNode *node = stack->head;
    int data = node->data;

    stack->head = node->next;

    free(node);

    return data;
}

void stll_print(StackLinkedList *stack) {
    printf("\n----------------------------\n");
    printf("Linked List\n\nSize: %d\n\n", stll_size(stack));

    struct StackNode *current = stack->head;

    if (stll_is_empty(stack)) {

        printf("Head: Null");
        printf("StackLinkedList: Empty");
    } else {
        printf("Head: %d\n", stack->head->data);
        printf("StackLinkedList: ");

        while (current != nullptr) {
            printf("%d ", current->data);
            current = current->next;
        }
    }

    printf("\n----------------------------\n");
}