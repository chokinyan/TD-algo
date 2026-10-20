#ifndef MY_QUEUE
#define MY_QUEUE

struct cell {
    long long value;
    struct cell* next;
};

struct queue_s {
    struct cell* head;
    struct cell* tail;
};

typedef struct queue_s* queue;

queue new_queue();

void Enqueue(queue que, long long value);

long long Dequeue(queue que);

long long peek(queue que);

#endif /* MY_QUEUE */
