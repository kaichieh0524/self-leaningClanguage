// Target Sum (medium)
// Runtime: 28 ms, faster than 72.41% of C online submissions for Target Sum.
// Memory Usage: 33.2 MB, less than 27.59% of C online submissions for Target Sum.


int findTargetSumWays(int* nums, int numsSize, int S){
    int** dp = malloc(sizeof(int*)*numsSize);
    for (int i = 0; i < numsSize; i++){
        dp[i] = calloc(2001,sizeof(int));
    }
    dp[0][nums[0] + 1000] += 1;
    dp[0][-nums[0] + 1000] += 1;
    for (int i = 1; i < numsSize; i++){
        for (int sum = -1000; sum <= 1000; sum++){
            if (dp[i-1][sum + 1000] > 0){
                dp[i][sum + nums[i] + 1000] += dp[i - 1 ][sum + 1000];
                dp[i][sum - nums[i] + 1000] += dp[i - 1 ][sum + 1000];
            }
        }
    }
     return S > 1000 ? 0 : dp[numsSize - 1][S + 1000];   
}