// Coin Change (medium)
// Runtime: 28 ms, faster than 85.65% of C online submissions for Coin Change.
// Memory Usage: 9.6 MB, less than 50.00% of C online submissions for Coin Change.

int coinChange(int* coins, int coinsSize, int amount){
    if (amount == 0){return 0;}

    int* ans = malloc(sizeof(int)*(amount+1));  
    for (int i = 0; i < amount+1;i++){
        ans[i] = amount+1;
    }
    ans[0]=0;    
    for (int i = 1; i < amount+1; i++){
        for (int j = 0; j < coinsSize; j++){
            if (i>=coins[j]){
                ans[i] = ans[i-coins[j]]+1 < ans[i] ? ans[i-coins[j]]+1 : ans[i];
            }
        }
    }
     int solution = ans[amount] > amount ? -1 : ans[amount];
     return solution;
}
