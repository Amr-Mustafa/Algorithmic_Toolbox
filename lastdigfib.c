#include <stdio.h>

// A function to calculate the last digit of the nth fibonacci number
int lastDigFib (long long n) {
    if (n < 2) {
        return n;
    } else {
        int elements[n], i;
        elements[0] = 0;
        elements[1] = 1;
        for (i = 2; i <= n; i++) {
            // The last digit of the nth fib number is the last digit of the sum of the last digits of the n-1 and n-2 fib numbers
            elements[i] = (elements[i-1] + elements[i-2]) % 10;
        }
        return elements[i-1];
    }
}

int main (void) {
    long long n;
    scanf("%lld", &n);
    printf("%d\n", lastDigFib(n));
    return 0;
}