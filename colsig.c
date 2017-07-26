/** PROBLEM STATEMENT
 * You are responsible for collecting signatures from all tenants of a certain building.
 * For each tenant, you know a period of time when he or she is at home.
 * You would like to collect all signatures by visiting the building as few times as possible.
 **/
 
#include <stdio.h>
#include <stdbool.h>

typedef struct timeperiod {
    int start;
    int end;
} TimePeriod;

/**
 * A function that sorts the TimePeriods w.r.t the end time, given an array of TimePeriods, length of the array.
**/
void SortTimePeriodsEND (TimePeriod elements[], int length) {
    for (int pass = 0; pass < length; pass++) {
        for (int i = 0; i < length - pass - 1; i++) {
            if (elements[i].end > elements[i+1].end) {
                TimePeriod temp = elements[i+1];
                elements[i+1] = elements[i];
                elements[i] = temp;
            }
        }
    }
}

/**
 * Given two TimePeriods it returns true if they are overlaping and false otherwise.
**/
bool AreOverlaping (TimePeriod p1, TimePeriod p2) {
    if (p2.start <= p1.end && p2.end >= p1.start)
        return true;
    
    return false;
}


int main (void) {
    
    // 1. Read the number of time periods of all tenants.
    int n, i, j = 0, k = 0;
    scanf("%d", &n);
    
    // 2. Read the start and end of each time period.
    TimePeriod periods[n];
    int points[n];
    for (i = 0; i < n; i++) {
        scanf("%d%d", &periods[i].start, &periods[i].end);
    }
    
    //3. Iterate over all time periods.
    SortTimePeriodsEND (periods, n);
    TimePeriod currentMin;
    while (j < n) {
        currentMin = periods[j];
        points[k] = currentMin.end;
        j++;
        k++;
        
        // We need to skip all periods already covered.
        while (AreOverlaping (currentMin, periods[j]) && j < n) {
            j++;
        }
    }
    
    // 4. Print the required output
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", points[i]);
    }
    printf("\n");
    
    return 0;
}