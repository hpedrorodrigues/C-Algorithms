#ifndef QUEUE_LINKED_LIST_TEST_H
#define QUEUE_LINKED_LIST_TEST_H

#include <assert.h>
#include "../../suite/suite.h"
#include "queue/linked_list/queue.h"

void run_all_queue_linked_list_tests();

void qll_whenEnqueuingAElement_thenItMustBeTheLastElementTest();

void qll_whenDequeuing_thenTheFirstElementMustBeReturnedAndDeletedTest();

#endif