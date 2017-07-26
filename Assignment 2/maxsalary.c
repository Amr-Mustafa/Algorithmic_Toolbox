#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int numDigits (int a) {
    int num = 0;
    while (a != 0) {
        a /= 10;
        num++;
    }
    return num;
}

bool isGreaterOrEqual (int a, int b) {
    return ((a * pow (10, numDigits(b))) + b) >= ((b * pow (10, numDigits(a))) + a);
}

int main (void) {
    int n;
    scanf("%d", &n);
    
    int numbers[n];
    int answer = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int j = n;
    while (j > 0) {
        int maxDigit = -99999999;
        for (int i = 0; i < n; i++) {
            if (isGreaterOrEqual(numbers[i], maxDigit))
                maxDigit = numbers[i];
        }
        
        printf("%d", maxDigit);
        
        for (int k = 0; k < n; k++) {
            if (numbers[k] == maxDigit) {
                numbers[k] = -1;
                break;
            }
        }
        
        j--;
    }

    printf("\n");
}
