#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int prime_naive(unsigned int n);
unsigned int prime_fast(unsigned int n);

int main(void) {
    unsigned int n = 1000000;

    clock_t t1 = clock();
    printf("prime naive : %u\n", prime_naive(n));
    clock_t t2 = clock();
    printf("temps naive : %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    clock_t t3 = clock();
    printf("prime fast : %u\n", prime_fast(n));
    clock_t t4 = clock();
    printf("temps fast : %f\n", (double)(t4 - t3) / CLOCKS_PER_SEC);

    return 0;
}

unsigned int prime_naive(unsigned int n) {
    unsigned int count = 0;

    for (unsigned long long k = 2; k <= n; k++) {
        bool is_prime = true;

        for (unsigned long long d = 2; d * d <= k; d++) {
            if (k % d == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            count++;
    }
    return count;
}

unsigned int prime_fast(unsigned int n) {
    bool* prime_numbers = malloc(sizeof(bool) * (n + 1));

    if (prime_numbers == NULL)
        return 0;

    for (unsigned int i = 0; i <= n; i++)
        prime_numbers[i] = true;
    prime_numbers[0] = false;
    if (n >= 1)
        prime_numbers[1] = false;

    for (unsigned long long i = 2; i * i <= n; i++) {
        if (prime_numbers[i]) {
            for (unsigned long long j = i * i; j <= n; j += i)
                prime_numbers[j] = false;
        }
    }

    unsigned int count = 0;
    for (unsigned int i = 0; i <= n; i++) {
        if (prime_numbers[i])
            count++;
    }

    free(prime_numbers);
    return count;
}
