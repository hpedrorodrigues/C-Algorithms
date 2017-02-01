#include "linked_list.h"

DoublyLinkedList *dll_new_instance() {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

    check_address(list);

    list->head = list->tail = nullptr;

    return list;
}

struct DoublyLinkedListNode *dll_new_node(int value) {
    struct DoublyLinkedListNode *node = malloc(sizeof(struct DoublyLinkedListNode));

    check_address(node);

    node->previous = nullptr;
    node->next = nullptr;
    node->data = value;

    return node;
}

void dll_destroy(DoublyLinkedList *list) {
    struct DoublyLinkedListNode *current = list->head;
    struct DoublyLinkedListNode *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int dll_size(DoublyLinkedList *list) {
    struct DoublyLinkedListNode *current = list->head;
    int size = 0;

    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
}

bool dll_is_empty(DoublyLinkedList *list) {
    return list->head == nullptr && list->tail == nullptr;
}

void dll_prepend(DoublyLinkedList *list, int value) {
    struct DoublyLinkedListNode *node = dll_new_node(value);

    node->next = list->head;

    if (list->head != nullptr) {
        list->head->previous = node;
    }

    list->head = node;

    if (list->tail == nullptr) {
        list->tail = node;
    }
}

void dll_append(DoublyLinkedList *list, int value) {
    struct DoublyLinkedListNode *node = dll_new_node(value);

    if (dll_is_empty(list)) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        node->previous = list->tail;
        list->tail = node;
    }
}

int dll_head(DoublyLinkedList *list) {
    if (dll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    return list->head->data;
}

int dll_tail(DoublyLinkedList *list) {
    if (dll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    return list->tail->data;
}

int dll_pop_head(DoublyLinkedList *list) {
    if (dll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    struct DoublyLinkedListNode *current = list->head;
    int data = current->data;

    list->head = list->head->next;

    if (list->head != nullptr) {
        list->head->previous = nullptr;
    }

    if (list->tail == current) {
        list->tail = list->head;
    }

    free(current);

    return data;
}

int dll_pop(DoublyLinkedList *list) {
    if (dll_is_empty(list)) {
        printf("List is empty.\n");
        return null;
    }

    int data = list->tail->data;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = nullptr;
        return data;
    } else {
        struct DoublyLinkedListNode *current = list->tail;

        list->tail = list->tail->previous;
        list->tail->next = nullptr;

        free(current);

        return data;
    }
}

void dll_insert_at(int index, DoublyLinkedList *list, int value) {
    if (!_dll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return;
    } else if (dll_is_empty(list)) {
        struct DoublyLinkedListNode *node = dll_new_node(value);
        list->head = list->tail = node;
    } else {
        struct DoublyLinkedListNode *current = list->head;

        while (--index != 0) {
            current = current->next;
        }

        struct DoublyLinkedListNode *next = current->next;
        struct DoublyLinkedListNode *node = dll_new_node(value);

        node->next = next;
        next->previous = node;
        current->next = node;
        node->previous = current;
    }
}

int dll_get_at(int index, DoublyLinkedList *list) {
    if (!_dll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return null;
    }

    unsigned int position = 0;
    struct DoublyLinkedListNode *current = list->head;

    while (position < index) {
        position++;
        current = current->next;
    }

    return current->data;
}

void dll_remove_at(int index, DoublyLinkedList *list) {
    if (!_dll_is_valid_index(index, list)) {
        printf("Invalid index: %d.\n", index);
        return;
    } else if (dll_is_empty(list)) {
        printf("Cannot remove from a empty list");
        return;
    } else if (list->head == list->tail) {
        list->head = list->tail = nullptr;
    } else {
        struct DoublyLinkedListNode *previous = list->head;

        while (--index != 0) {
            previous = previous->next;
        }

        struct DoublyLinkedListNode *current = previous->next;
        struct DoublyLinkedListNode *after = current->next;

        previous->next = after;

        if (current == list->tail) {
            list->tail = previous;
        }

        if (after != nullptr) {
            after->previous = previous;
        }

        free(current);
    }
}

void dll_remove_value(DoublyLinkedList *list, int value) {
    if (dll_is_empty(list)) {
        printf("Cannot remove from a empty list");
        return;
    } else {
        struct DoublyLinkedListNode *current = list->head;
        struct DoublyLinkedListNode *previous = list->head;

        while (current != nullptr) {
            if (list->head->data == value) {
                struct DoublyLinkedListNode *node = list->head;

                if (list->head == list->tail) {
                    list->head = list->tail = nullptr;
                } else {
                    list->head = list->head->next;
                    list->head->previous = nullptr;
                }

                previous = current = list->head;

                free(node);
            } else {

                if (current->data == value) {
                    struct DoublyLinkedListNode *node = current;
                    previous->next = current->next;
                    current->next->previous = previous;

                    free(node);
                }

                previous = current;
                current = current->next;
            }
        }
    }
}

DoublyLinkedList *dll_reverse(DoublyLinkedList *list) {
    if (!dll_is_empty(list)) {
        DoublyLinkedList *new = dll_new_instance();
        struct DoublyLinkedListNode *current = list->head;

        while (current != nullptr) {
            dll_prepend(new, current->data);
            current = current->next;
        }

        return new;
    }

    return nullptr;
}

bool _dll_is_valid_index(int index, DoublyLinkedList *list) {
    return index >= 0 && index < dll_size(list);
}

void dll_print(DoublyLinkedList *list) {
    printf("\n----------------------------\n");
    struct DoublyLinkedListNode *current = list->head;

    printf("Linked List\n\nSize: %d\n\n", dll_size(list));

    if (dll_is_empty(list)) {

        printf("Head: Null\n");
        printf("Tail: Null\n");
        printf("List: Empty\n");
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