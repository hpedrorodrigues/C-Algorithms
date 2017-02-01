#ifndef QUEUE_ARRAY_TEST_H
#define QUEUE_ARRAY_TEST_H

#include <assert.h>
#include "../../suite/suite.h"
#include "queue/array/queue.h"

void run_all_queue_array_tests();

void qa_whenEnqueuingAElement_thenItMustBeTheLastElementTest();

void qa_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest();

#endif