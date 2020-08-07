// Longest Increasing Subsequence (medium)
// untime: 32 ms, faster than 49.38% of C online submissions for Longest Increasing Subsequence.
// Memory Usage: 5.5 MB, less than 56.25% of C online submissions for Longest Increasing Subsequence.

int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {return 0;}
    int* ans = calloc(numsSize,sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        ans[i] = 1;
        for (int j = 0; j < i; j++){
            if (nums[i]>nums[j]){
                ans[i] = fmax(ans[j]+1,ans[i]);
            }
           
        }
    }
    int ma = 1;
    for (int i = 0; i < numsSize; i++){
        ma = fmax(ma,ans[i]);
    }
    return ma;
}