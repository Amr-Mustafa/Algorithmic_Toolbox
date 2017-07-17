/** Algorithm for calculating Fi % m
 * 1st: We need to calculate the length of the Pisano period for that specific m
 * 2nd: Then we need to calculate the Pisano period for that same m
 * 3rd: Then we need to find the index of the result located in that period
 * 4th: Finally Return the result
**/
#include <stdio.h>
#include <stdbool.h>
 
/* 
   A function to calculate the length of the Pisano period for a given m.
   The function returns the length of the Pisano period for the given m if
   successfull, otherwise it returns -1 indicating error.
*/
int PisanoLength (long long m) {
    
    // Pisano Period is not defined for m <= 1 so we throw an error.
    if (m <= 1) {
        return -1;
    }
    
    // We initialized the length to 3 because we already have two elements in previous and current, and the third element will
    // be calculated before entering the loop.
    int length = 3, previous = 0, current = 1;
    
    // Calculating a new current element and updating the state.
    int temp = current;
    current = ((current % m) + (previous % m)) % m;
    previous = temp;
    
    // We keep incrementing the length untill we stumble upon the start of a new period
    while (true) {
        if (previous == 0 && current == 1) {
            // We found the start of a new period.
            break;
        } else {
            // Calculating a new current element and updating the state.
            int temp2 = current;
            current = ((current % m) + (previous % m)) % m;
            previous = temp2;
            // Incrementing the length of the period.
            length++;
        }
    }
    
    // We had to subtract 2 from the length because we didn't break from the loop until previous equaled zero and current
    // equaled one which caused 2 extra iterations.
    return length - 2;
}

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

int main (void) {
    int l;
    long long n, m;
    scanf("%lld%lldd", &n, &m);
    
    l = PisanoLength(m);
    
    int period[l];
    PisanoPeriod(period, m, l);
    
    int index = n % l;
    printf("%d\n", period[index]);
    return 0;
}
