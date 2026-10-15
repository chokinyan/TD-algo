#ifndef MY_LIST
#define MY_LIST

typedef struct double_list {
    long long data;
    struct double_list* next;
    struct double_list* previous;
} double_list;

double_list new_list(long long first_val);

void insert(double_list* l, long long value, unsigned long index);
void supress(double_list* l, unsigned long index);

long long get(double_list* l, unsigned long index);

#endif /* MY_LIST */
