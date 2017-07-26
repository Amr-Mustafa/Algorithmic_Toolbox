/** PROBLEM STATEMENT
 * The goal in this problem is to find the minimum number of coins needed to change the input value
 * (an integer) into coins with denominations 1, 5, and 10.
 **/

#include <stdio.h>

/**
 * Returns the minimum number of coins required to change the input value into coins.
**/
int ReturnChange (int m) {
    int totNum = 0;
    while (m > 0) {
        if (m >= 10) {
            m -= 10;
            totNum++;
        } else if (m >= 5) {
            m -= 5;
            totNum++;
        } else {
            m -= 1;
            totNum++;
        }
    }
    return totNum;
}

int main (void) {
    int m;
    scanf("%d", &m);
    printf("%d\n", ReturnChange (m));
    return 0;
}
    