#ifndef MY_LIST
#define MY_LIST

typedef struct circular_list {
    long long data;
    struct circular_list* next;
} circular_list;

circular_list new_list(long long first_val);

void insert(circular_list* l, long long value, unsigned long index);
void supress(circular_list* l, unsigned long index);

long long get(circular_list* l, unsigned long index);

#endif /* MY_LIST */
