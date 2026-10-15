#include "array.h"
#include <stdlib.h>
#include <string.h>

array new_array() {
    array ar;

    ar.capacity = DEFAULT_SIZE;
    ar.size = 0;

    ar.data = calloc(DEFAULT_SIZE, sizeof(long long));

    if (ar.data == NULL)
        ar.capacity = 0;

    return ar;
}

long long get(array* arr, unsigned long index) {
    if (index >= arr->size)
        return 0;

    long long val = arr->data[index];
    return val;
}

void insert(array* arr, unsigned long index, long long value) {
    if (index > arr->size)
        return;

    if (arr->size >= arr->capacity) {
        long long* tmp =
            realloc(arr->data, sizeof(long long) * (arr->capacity + 100));

        if (tmp == NULL)
            return;

        arr->data = tmp;
        arr->capacity += 100;
    }

    memmove(&arr->data[index + 1], &arr->data[index],
            (arr->size - index) * sizeof(long long));

    arr->data[index] = value;
    arr->size++;
}

void delete_index(array* arr, unsigned long index) {
    if (index >= arr->size)
        return;

    memmove(&arr->data[index], &arr->data[index + 1],
            (arr->size - index - 1) * sizeof(long long));

    arr->size--;
}
