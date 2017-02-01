#include "queue.h"

const int QA_MinInitialCapacity = 1;
const int QA_MinCapacity = 16;
const int QA_GrowthFactor = 2;
const int QA_ShrinkFactor = 4;

QueueArray *qa_new_instance() {
    QueueArray *queue = malloc(sizeof(QueueArray));

    check_address(queue);

    queue->size = 0;
    queue->capacity = QA_MinCapacity;
    queue->data = (int *) malloc(sizeof(int) * QA_MinCapacity);

    check_address(queue->data);

    return queue;
}

void qa_destroy(QueueArray *queue) {
    free(queue->data);
    free(queue);
}

void qa_resize(QueueArray *queue, int candidate_size) {
    if (queue->size > candidate_size && queue->size < queue->capacity / QA_ShrinkFactor) {
        qa_downsize(queue);
    } else if (queue->size < candidate_size && queue->size == queue->capacity) {
        qa_upsize(queue);
    } else {
        // Nothing to do
    }
}

int qa_determine_capacity(int capacity) {
    if (capacity < QA_MinInitialCapacity) {
        return null;
    } else if (capacity < QA_MinCapacity) {
        return QA_MinCapacity;
    }

    int real_capacity = QA_MinInitialCapacity;
    while (capacity > real_capacity / QA_GrowthFactor) {
        real_capacity *= QA_GrowthFactor;
    }

    return real_capacity;
}

void qa_upsize(QueueArray *queue) {
    int old_capacity = queue->capacity;
    int new_capacity = qa_determine_capacity(old_capacity);
    int *new_data = (int *) malloc(sizeof(int) * new_capacity);

    check_address(new_data);

    for (register int i = 0; i < old_capacity; ++i) {
        *(new_data + i) = *(queue->data + i);
    }

    free(queue->data);

    queue->data = new_data;
    queue->capacity = new_capacity;
}

void qa_downsize(QueueArray *queue) {
    int old_capacity = queue->capacity;
    int new_capacity = queue->capacity / QA_GrowthFactor;

    if (new_capacity < QA_MinCapacity) {
        new_capacity = QA_MinCapacity;
    }

    if (new_capacity != old_capacity) {
        int *new_data = (int *) malloc(sizeof(int) * new_capacity);

        check_address(new_data);

        for (register int i = 0; i < queue->size; ++i) {
            *(new_data + i) = *(queue->data + i);
        }

        free(queue->data);

        queue->data = new_data;
        queue->capacity = new_capacity;
    }
}

int qa_size(QueueArray *queue) {
    return queue->size;
}

bool _qa_is_empty(QueueArray *queue) {
    return qa_size(queue) == 0;
}

void qa_enqueue(QueueArray *queue, int value) {
    qa_resize(queue, queue->size + 1);

    *(queue->data + queue->size) = value;
    queue->size++;
}

int qa_dequeue(QueueArray *queue) {
    if (_qa_is_empty(queue)) {
        return null;
    }

    int value = *(queue->data);

    for (register int i = 0; i < queue->size; i++) {
        *(queue->data + i) = *(queue->data + i + 1);
    }

    *(queue->data + queue->size) = 0;

    qa_resize(queue, queue->size - 1);

    queue->size--;

    return value;
}

void qa_print(QueueArray *queue) {
    printf("Size: %d\n", queue->size);
    printf("Capacity: %d\n", queue->capacity);
    printf("%s\n\n", "Items:");

    for (register int i = 0; i < queue->size; i++) {
        printf("%d) %d\n", i, *(queue->data + i));
    }

    printf("---------\n\n");
}