// Coin Change 2 (medium)
// Runtime: 8 ms, faster than 53.85% of C online submissions for Coin Change 2.
// Memory Usage: 5.5 MB, less than 84.62% of C online submissions for Coin Change 2.


int change(int amount, int* coins, int coinsSize){
    int* dp = calloc(amount+1,sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < coinsSize; i++){
        for (int j = coins[i]; j < amount + 1;  j++){
                dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amount];
}