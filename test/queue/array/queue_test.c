#include "queue_test.h"

void run_all_queue_array_tests() {
    print_header("Queue - Array");

    run_test("whenEnqueuingAElement_thenItMustBeTheLastElementTest",
             qa_whenEnqueuingAElement_thenItMustBeTheLastElementTest);
    run_test("whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest",
             qa_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest);

    print_footer();
}

void qa_whenEnqueuingAElement_thenItMustBeTheLastElementTest() {
    QueueArray *queue = qa_new_instance();

    qa_enqueue(queue, 1);

    assert(qa_dequeue(queue) == 1);

    qa_enqueue(queue, 3);
    qa_enqueue(queue, 4);

    assert(qa_dequeue(queue) == 3);
    assert(qa_dequeue(queue) == 4);

    qa_destroy(queue);
}

void qa_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest() {
    QueueArray *queue = qa_new_instance();

    qa_enqueue(queue, 3);
    qa_enqueue(queue, 4);
    qa_enqueue(queue, 5);

    assert(qa_dequeue(queue) == 3);
    assert(qa_dequeue(queue) == 4);
    assert(qa_dequeue(queue) == 5);

    qa_destroy(queue);
}