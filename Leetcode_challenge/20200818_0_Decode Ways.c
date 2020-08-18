// Decode Ways (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Decode Ways.
// Memory Usage: 5.2 MB, less than 52.76% of C online submissions for Decode Ways.


int numDecodings(char * s){
    int dp[4096];
    int len = strlen(s);
    if (s[0] == '0' || len == 0){
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= len; i++){
        dp[i] = s[i-1] == '0' ? 0 : dp[i-1];
        if (i > 1){
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6' )){
                dp[i] += dp[i-2];
            }
        }
    }
    return dp[len];
}

