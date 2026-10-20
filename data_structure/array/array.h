#ifndef MY_ARRAY
#define MY_ARRAY

#include <stdbool.h>

#define DEFAULT_SIZE 1000

typedef struct {
    long long* data;
    unsigned long size;
    unsigned long capacity;
} array;

array new_array();
array copy_array(array* arr);

void insert(array* arr, unsigned long index, long long value);
void delete_index(array* arr, unsigned long index);
void edit(array* arr, unsigned long index, long long value);

bool is_sorted_increasing(array* arr);
void swap_int(array* arr, unsigned long first, unsigned long second);

long long get(array* arr, unsigned long index);

#endif /* MY_ARRAY */
