#include <stdio.h>

#define PISANO_LENGTH 60 // The lengnth of the Pisano period for 10 is 60.
#define M 10

/* 
   A function to calculate the Pisano period given a certain m and an array and the length l of
   the Pisano period for the given m, computed by PisanoLength function. Note: m >= 2.
*/
void PisanoPeriod (int elements[], long long m, int l) {
    int i;
    elements[0] = 0;
    elements[1] = 1;
    for (i = 2; i < l; i++) {
        elements[i] = ((elements[i-1]) + (elements[i-2])) % m;
    }
}

int lastDigFibSum (long long n) {
    int period[PISANO_LENGTH];
    PisanoPeriod (period, M, PISANO_LENGTH);
    int index = (n + 2) % PISANO_LENGTH;
    if (period[index] == 0)
        return 9;
    else
        return period[index] - 1;
}

// A function to calculate the last digit of the nth fibonacci number
int lastDigFib (long long n) {
    int period[PISANO_LENGTH];
    PisanoPeriod (period, M, PISANO_LENGTH);
    int index = n % PISANO_LENGTH;
    if (period[index] == 0)
        return 9;
    else
        return period[index];
}

int main (void) {
    long long m, n;
    int res;
    scanf("%lld%lld", &m, &n);
    if (m == n)
        res = lastDigFib(n);
    else
        if (lastDigFibSum(n) < lastDigFibSum(m-1))
            res =  lastDigFibSum(n) + 10 - lastDigFibSum(m-1);
        else
            res =  lastDigFibSum(n) - lastDigFibSum(m-1);
    printf("%d\n", res);
}