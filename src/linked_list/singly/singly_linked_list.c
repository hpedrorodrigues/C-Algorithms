#include "singly_linked_list.h"

SinglyLinkedList *sll_new_instance() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));

    check_address(list);

    list->head = list->tail = nullptr;

    return list;
}

struct SinglyLinkedListNode *sll_new_node(int value) {
    struct SinglyLinkedListNode *node = malloc(sizeof(struct SinglyLinkedListNode));

    check_address(node);

    node->next = nullptr;
    node->data = value;

    return node;
}

void sll_destroy(SinglyLinkedList *list) {
    struct SinglyLinkedListNode *current = list->head;
    struct SinglyLinkedListNode *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int sll_size(SinglyLinkedList *list) {
    struct SinglyLinkedListNode *current = list->head;
    int size = 0;

    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
}

bool sll_is_empty(SinglyLinkedList *list) {
    return list->head == nullptr && list->tail == nullptr;
}

void sll_prepend(SinglyLinkedList *list, int value) {
    struct SinglyLinkedListNode *node = sll_new_node(value);

    node->next = list->head;
    list->head = node;

    if (list->tail == nullptr) {
        list->tail = node;
    }
}

void sll_append(SinglyLinkedList *list, int value) {
    struct SinglyLinkedListNode *node = sll_new_node(value);

    if (sll_is_empty(list)) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

int sll_head(SinglyLinkedList *list) {
    if (sll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    return list->head->data;
}

int sll_tail(SinglyLinkedList *list) {
    if (sll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    return list->tail->data;
}

int sll_pop_head(SinglyLinkedList *list) {
    if (sll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    struct SinglyLinkedListNode *node = list->head;
    int data = node->data;

    list->head = list->head->next;

    if (list->tail == node) {
        list->tail = list->head;
    }

    free(node);

    return data;
}

int sll_pop(SinglyLinkedList *list) {
    if (sll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    int data = list->tail->data;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = nullptr;
        return data;
    } else {
        struct SinglyLinkedListNode *current = list->head;
        struct SinglyLinkedListNode *previous = current;

        while (current != list->tail) {
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;
        list->tail = previous;

        free(current);

        return data;
    }
}

void sll_insert_at(int index, SinglyLinkedList *list, int value) {
    if (!_sll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return;
    }

    unsigned int position = 0;

    struct SinglyLinkedListNode *current = list->head,
            *previous = list->head,
            *node = sll_new_node(value);

    while (position < index && current != nullptr) {
        position++;
        previous = current;
        current = current->next;
    }

    if (sll_is_empty(list)) {
        list->head = list->tail = node;
    } else if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else if (current == list->tail) {
        node->next = current;
        previous->next = node;
    } else {
        node->next = previous->next;
        previous->next = node;
    }
}

int sll_get_at(int index, SinglyLinkedList *list) {
    if (!_sll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return null;
    }

    unsigned int position = 0;
    struct SinglyLinkedListNode *current = list->head;

    while (position < index) {
        position++;
        current = current->next;
    }

    return current->data;
}

void sll_remove_at(int index, SinglyLinkedList *list) {
    if (!_sll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return;
    } else if (sll_is_empty(list)) {
        printf("Cannot remove from a empty list");
        return;
    } else if (list->head == list->tail) {
        list->head = list->tail = nullptr;
    } else if (index == 0) {
        struct SinglyLinkedListNode *node = list->head;
        list->head = list->head->next;
        free(node);
    } else {
        struct SinglyLinkedListNode *current = list->head;
        struct SinglyLinkedListNode *previous = list->head;

        unsigned int position = 0;

        while (position < index) {
            position++;
            previous = current;
            current = current->next;
        }

        if (current == list->tail) {
            list->tail = previous;
        }

        previous->next = current->next;
        free(current);
    }
}

void sll_remove_value(SinglyLinkedList *list, int value) {
    if (sll_is_empty(list)) {
        printf("Cannot remove from a empty list");
        return;
    } else {
        struct SinglyLinkedListNode *current = list->head;
        struct SinglyLinkedListNode *previous = list->head;

        while (current != nullptr) {
            if (list->head->data == value) {
                struct SinglyLinkedListNode *node = list->head;

                if (list->head == list->tail) {
                    list->head = list->tail = nullptr;
                } else {
                    list->head = list->head->next;
                }

                previous = current = list->head;

                free(node);
            } else {

                if (current->data == value) {
                    struct SinglyLinkedListNode *node = current;
                    previous->next = current->next;
                    free(node);
                }

                previous = current;
                current = current->next;
            }
        }
    }
}

SinglyLinkedList *sll_reverse(SinglyLinkedList *list) {
    if (!sll_is_empty(list)) {
        SinglyLinkedList *new = sll_new_instance();
        struct SinglyLinkedListNode *current = list->head;

        while (current != nullptr) {
            sll_prepend(new, current->data);
            current = current->next;
        }

        return new;
    }

    return nullptr;
}

bool _sll_is_valid_index(int index, SinglyLinkedList *list) {
    return index >= 0 && index < sll_size(list);
}

void sll_print(SinglyLinkedList *list) {
    printf("\n----------------------------\n");
    struct SinglyLinkedListNode *current = list->head;

    printf("Linked List\n\nSize: %d\n\n", sll_size(list));

    if (sll_is_empty(list)) {

        printf("Head: Null");
        printf("Tail: Null");
        printf("List: Empty");
    } else {
        printf("Head: %d\n", list->head->data);
        printf("Tail: %d\n\n", list->tail->data);
        printf("List: ");

        while (current != nullptr) {
            printf("%d ", current->data);
            current = current->next;
        }
    }

    printf("\n----------------------------\n");
}