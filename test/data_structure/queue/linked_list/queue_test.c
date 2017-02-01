#include "queue_test.h"

void run_all_queue_linked_list_tests() {
    print_header("Queue - Linked List");

    run_test("whenEnqueuingAElement_thenItMustBeTheLastElementTest",
             qll_whenEnqueuingAElement_thenItMustBeTheLastElementTest);
    run_test("whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest",
             qll_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest);

    print_footer();
}

void qll_whenEnqueuingAElement_thenItMustBeTheLastElementTest() {
    QueueLinkedList *queue = qll_new_instance();

    qll_enqueue(queue, 1);

    assert(qll_dequeue(queue) == 1);

    qll_enqueue(queue, 1);
    qll_enqueue(queue, 2);

    assert(qll_dequeue(queue) == 1);
    assert(qll_dequeue(queue) == 2);

    qll_destroy(queue);
}

void qll_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest() {
    QueueLinkedList *queue = qll_new_instance();

    qll_enqueue(queue, 3);
    qll_enqueue(queue, 4);
    qll_enqueue(queue, 5);

    assert(qll_dequeue(queue) == 3);
    assert(qll_dequeue(queue) == 4);
    assert(qll_dequeue(queue) == 5);

    qll_destroy(queue);
}