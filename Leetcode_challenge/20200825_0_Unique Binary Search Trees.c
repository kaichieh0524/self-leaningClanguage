// Unique Binary Search Trees (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Unique Binary Search Trees.
// Memory Usage: 5.1 MB, less than 56.52% of C online submissions for Unique Binary Search Trees.


int numTrees(int n){
    int* dp = calloc(20,sizeof(int));
    dp[0] = 1;
    for (int i = 1; i  <= n; i++){
        for (int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }    
    return dp[n];
}