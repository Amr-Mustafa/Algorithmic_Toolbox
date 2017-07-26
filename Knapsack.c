/** PSEUDOCODE FOR THE ALGORITHM IMPLEMENTED
 * 1. While Knapscak is not full.
 * 2. Find the most valuable item.
 * 3. If it fits into the knapsack then take it all, otherwise take as much as possible.
 * 4. Update.
 */

#include <stdio.h>
#include <stdbool.h>

int mostValuable (int numbers[][2], int n) {
    double mostValuable = 0;
    int mostValuableIndex = 0;
    for (int i = 0; i < n; i++) {
        if ((numbers[i][0] * 1.0 / numbers[i][1]) > mostValuable) {
            mostValuable = (numbers[i][0] * 1.0 / numbers[i][1]);
            mostValuableIndex = i;
        }
    }
    return mostValuableIndex;
}

int main (void) {
    // Read the numbers of items n and the capacity W of the knapsack.
    int n, W;
    scanf("%d%d", &n, &W);
    
    // Read the weight and value of each item.
    int value_weight[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &value_weight[i][0], &value_weight[i][1]);
    }
    
    //printf("%d %d\n", value_weight[mostValuable(value_weight, n)][0], value_weight[mostValuable(value_weight, n)][1]);
    
    // Fill the Knapsack while not empty.
    double totalVal = 0;
    while (W > 0) {
        int mostValuableIndex = mostValuable(value_weight, n);
        if (value_weight[mostValuableIndex][1] == W) {
            
            totalVal += value_weight[mostValuableIndex][0];
            value_weight[mostValuableIndex][0] = 0;
            W = 0;
            
        } else if (value_weight[mostValuableIndex][1] > W) {
            
            totalVal += (value_weight[mostValuableIndex][0] * 1.0 / value_weight[mostValuableIndex][1]) * W;
            value_weight[mostValuableIndex][0] = 0;
            W = 0;
        }
        else {
            totalVal += (value_weight[mostValuableIndex][0] * 1.0 / value_weight[mostValuableIndex][1]) * value_weight[mostValuableIndex][1];
            W -= value_weight[mostValuableIndex][1];
            value_weight[mostValuableIndex][0] = 0;
        }
    }
    
    printf("%.4f\n", totalVal);
    return 0;
}