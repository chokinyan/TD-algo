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

void edit(array* arr, unsigned long index, long long value) {
    if (index >= arr->size)
        return;

    arr->data[index] = value;
}

bool is_sorted_increasing(array* arr) {

    for (unsigned long i = 0; i < arr->size - 1; i++) {
        if (get(arr, i) >= get(arr, i + 1))
            return false;
    }
    return true;
}

void swap_int(array* arr, unsigned long first, unsigned long second) {
    long long val1 = get(arr, first);
    long long val2 = get(arr, second);
    edit(arr, first, val2);
    edit(arr, second, val1);
}

array copy_array(array* arr) {
    array new_arr;

    new_arr.capacity = arr->capacity;
    new_arr.size = arr->size;
    new_arr.data = malloc(sizeof(long long) * new_arr.capacity);
    memcpy(new_arr.data, arr->data, new_arr.capacity * sizeof(long long));

    return new_arr;
}