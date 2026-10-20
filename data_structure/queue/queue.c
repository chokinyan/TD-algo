#include "queue.h"
#include <stdlib.h>

queue new_queue() {
    queue que = malloc(sizeof(struct queue_s));

    if (que == NULL)
        return NULL;

    que->head = NULL;
    que->tail = NULL;

    return que;
}

void Enqueue(queue que, long long value) {
    struct cell* new_cell = malloc(sizeof(struct cell));

    if (new_cell == NULL)
        return;

    new_cell->value = value;
    new_cell->next = NULL;

    if (que->tail == NULL) {
        que->head = new_cell;
    } else {
        que->tail->next = new_cell;
    }

    que->tail = new_cell;
}

long long Dequeue(queue que) {
    if (que->head == NULL)
        return -1;

    struct cell* temp = que->head;
    long long val = temp->value;

    que->head = temp->next;

    if (que->head == NULL)
        que->tail = NULL;

    free(temp);

    return val;
}

long long peek(queue que) {
    if (que->head == NULL)
        return -1;

    long long val = que->head->value;

    return val;
}
