/** PROBLEM STATEMENT
 * You have 𝑛 ads to place on a popular Internet page. For each ad, you know how
 * much is the advertiser willing to pay for one click on this ad. You have set up
 * slots on your page and estimated the expected number of clicks per day for each
 * slot. Now, your goal is to distribute the ads among the slots to maximize the
 * total revenue.
 * 
 * Basically, we need to place the ad with highest profit per click in the slot with the highest number of clicks per day.
 **/
 
#include <stdio.h>

void Sort (long long elements[], int length) {
    for (int pass = 0; pass < length; pass++) {
        for (int i = 0; i < length - pass - 1; i++) {
            if (elements[i] > elements[i+1]) {
                long long temp = elements[i+1];
                elements[i+1] = elements[i];
                elements[i] = temp;
            }
        }
    }
}

int main (void) {
    
    // 1. Read the number of ads.
    int n;
    scanf("%d", &n);
    
    // 2. Read the profit per click for each ad and the number of clicks per day for each slot.
    long long profit_click[n], click_slot[n];
    for (int i = 0; i < n; i++) {
       scanf("%lld", &profit_click[i]); 
    }
    
    for (int i = 0; i < n; i++) {
       scanf("%lld", &click_slot[i]); 
    }
    
    // 3. Sort the profit per click and clicks per day for each slot in ascending order.
    Sort (profit_click, n);
    Sort (click_slot, n);
    
    // 4. Calculate the max revenue.
    long long maxRev = 0;
    for (int i = 0; i < n; i++) {
        maxRev += (profit_click[i] * click_slot[i]);
    }
    
    // 5. Print the max revenue.
    printf("%lld\n", maxRev);
    
    return 0;
}