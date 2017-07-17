#include <stdio.h>

long fibSmall (int n) {
    long numbers[n+1];
    numbers[0] = 0;
    numbers[1] = 1;
    for (int i = 2; i <= n; i++) {
        numbers[i] = numbers[i-1] + numbers[i-2];
    }
    return numbers[n];
}

int main (void) {
    int n;
    scanf("%d", &n);
    printf("%ld\n", fibSmall(n));
    return 0;
}
