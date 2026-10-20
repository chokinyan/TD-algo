#include "../data_structure/array/array.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// is_sorted_ascending is define in "../data_structure/array/array.h"

unsigned long linear_search(array* arr, long long value);
unsigned long jump_search(array* arr, long long value);
unsigned long binary_search(array* arr, long long value);

int main(void) {
    srand(time(NULL));

    unsigned long n = 10000000;

    array a;
    a.data = malloc(n * sizeof(long long));
    a.size = n;
    a.capacity = n;

    a.data[0] = rand() % 10;
    for (unsigned long i = 1; i < n; i++)
        a.data[i] = a.data[i - 1] + 1 + rand() % 10;

    unsigned long idx = (rand() * 32768UL + rand()) % n;
    long long value = a.data[idx];

    printf("n = %lu, valeur cherchée = %lld (indice %lu)\n\n", n, value, idx);

    clock_t t = clock();
    unsigned long r = linear_search(&a, value);
    printf("linear : indice %lu, %f s\n", r,
           (double)(clock() - t) / CLOCKS_PER_SEC);

    t = clock();
    r = jump_search(&a, value);
    printf("jump   : indice %lu, %f s\n", r,
           (double)(clock() - t) / CLOCKS_PER_SEC);

    t = clock();
    r = binary_search(&a, value);
    printf("binary : indice %lu, %f s\n", r,
           (double)(clock() - t) / CLOCKS_PER_SEC);

    free(a.data);
    return 0;
}

unsigned long linear_search(array* arr, long long value) {
    // Complexity time : O(n)
    // Complexity memory : O(1)

    for (unsigned long i = 0; i < arr->size; i++) {
        if (get(arr, i) == value)
            return i;
    }

    return -1;
}

unsigned long jump_search(array* arr, long long value) {
    // Complexity time : O(sqrt(n))
    // Complexity memory : O(1)

    if (!is_sorted_increasing(arr))
        return -1;

    unsigned long n = arr->size;

    unsigned long jump = (unsigned long)sqrt((double)n);

    unsigned long prev = 0;
    unsigned long i = jump;

    while (get(arr, (i < n ? i : n) - 1) < value) {
        prev = i;
        i += jump;
        if (prev >= n)
            return -1;
    }

    unsigned long end = i < n ? i : n;

    for (unsigned long j = prev; j < end; j++) {
        if (get(arr, j) == value)
            return j;
    }
    return -1;
}

unsigned long binary_search(array* arr, long long value) {
    // Complexity time : O(log(n))
    // Complexity memory : O(1)

    if (!is_sorted_increasing(arr))
        return -1;

    unsigned long low = 0;

    unsigned long n = arr->size - 1;

    unsigned long middle = 0;

    while (low < n) {
        middle = low + (unsigned long)((n - low) / 2);

        long long val = get(arr, middle);

        if (val == value)
            return val;
        else if (val > value)
            n = middle - 1;
        else
            low = middle + 1;
    }

    return -1;
}