/**
 * The last digit of the sum of the first n Fibonacci numbers is the last digit of the sum of the last digits of the first n Fibonacci numbers.
 */
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

int main (void) {
    long long n;
    scanf ("%lld", &n);
    printf ("%d\n", lastDigFibSum (n));
}