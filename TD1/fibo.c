#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long fibo_naiv(unsigned long long n);
unsigned long long fibo_dyn(unsigned long long n, unsigned long long* array);

int main(void) {
    unsigned long long n = 40;

    clock_t t1 = clock();
    printf("fibo 1 : %llu\n", fibo_naiv(n));
    clock_t t2 = clock();
    printf("fib naiv : %f \n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    clock_t t3 = clock();
    unsigned long long* arr = malloc((n + 1) * sizeof(unsigned long long));
    for (unsigned long long i = 0; i < n + 1; i++) {
        arr[i] = ULLONG_MAX;
    }
    printf("fibo 2 : %llu\n", fibo_dyn(n, arr));
    clock_t t4 = clock();
    printf("fib dyn : %f \n", (double)(t4 - t3) / CLOCKS_PER_SEC);

    free(arr);

    return 0;
}

unsigned long long fibo_naiv(unsigned long long n) {
    if (n <= 1) {
        return n;
    }
    return fibo_naiv(n - 1) + fibo_naiv(n - 2);
}

unsigned long long fibo_dyn(unsigned long long n, unsigned long long* array) {
    if (array[n] != ULLONG_MAX)
        return array[n];
    if (n <= 1)
        return n;
    array[n] = fibo_dyn(n - 1, array) + fibo_dyn(n - 2, array);
    return array[n];
}