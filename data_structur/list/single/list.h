#ifndef MY_LIST
#define MY_LIST

typedef struct single_list {
    long long data;
    struct single_list* next;
} single_list;

single_list new_list(long long first_val);

void insert(single_list* l, long long value, unsigned long index);
void supress(single_list* l, unsigned long index);

long long get(single_list* l, unsigned long index);

#endif /* MY_LIST */