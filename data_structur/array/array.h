#ifndef MY_ARRAY
#define MY_ARRAY

#define DEFAULT_SIZE 1000

typedef struct {
    long long* data;
    unsigned long size;
    unsigned long capacity;
} array;

array new_array();

void insert(array* arr, unsigned long index, long long value);
void delete_index(array* arr, unsigned long index);

long long get(array* arr, unsigned long index);

#endif /* MY_ARRAY */
