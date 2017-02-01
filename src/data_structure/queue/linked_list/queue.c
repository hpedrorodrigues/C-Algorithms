#include "queue.h"

QueueLinkedList *qll_new_instance() {
    QueueLinkedList *queue = malloc(sizeof(QueueLinkedList));

    check_address(queue);

    queue->head = nullptr;
    queue->tail = nullptr;

    return queue;
}

struct QueueNode *qll_new_node(int value) {
    struct QueueNode *node = malloc(sizeof(struct QueueNode));

    check_address(node);

    node->next = nullptr;
    node->data = value;

    return node;
}

void qll_destroy(QueueLinkedList *queue) {
    struct QueueNode *current = queue->head;
    struct QueueNode *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int qll_size(QueueLinkedList *queue) {
    struct QueueNode *current = queue->head;
    int size = 0;

    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
}

bool _qll_is_empty(QueueLinkedList *queue) {
    return queue->head == nullptr && queue->tail == nullptr;
}

void qll_enqueue(QueueLinkedList *queue, int value) {
    struct QueueNode *node = qll_new_node(value);

    if (_qll_is_empty(queue)) {
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

int qll_dequeue(QueueLinkedList *queue) {
    if (_qll_is_empty(queue)) {
        return nullptr;
    } else if (queue->head == queue->tail) {
        int data = queue->head->data;

        free(queue->head);

        queue->head = queue->tail = nullptr;

        return data;
    } else {

        struct QueueNode *node = queue->head;
        queue->head = queue->head->next;

        int data = node->data;
        free(node);

        return data;
    }
}

void qll_print(QueueLinkedList *queue) {
    printf("\n----------------------------\n");
    struct QueueNode *current = queue->head;

    printf("QueueLinkedList\n\nSize: %d\n\n", qll_size(queue));

    if (_qll_is_empty(queue)) {

        printf("Head: Null\n");
        printf("Tail: Null\n");
        printf("QueueLinkedList: Empty\n");
    } else {
        printf("Head: %d\n", queue->head->data);
        printf("Tail: %d\n\n", queue->tail->data);
        printf("QueueLinkedList: ");

        while (current != nullptr) {
            printf("%d ", current->data);
            current = current->next;
        }
    }

    printf("\n----------------------------\n");
}