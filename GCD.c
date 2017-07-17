#include <stdio.h>

long long GCD (long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return GCD (b, a % b);
    }
}

int main (void) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", GCD (a,b));
    return 0;
}