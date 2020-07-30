// Running Sum of 1d Array (easy)
// Runtime: 12 ms, faster than 26.89% of C online submissions for Running Sum of 1d Array.
// Memory Usage: 6.3 MB, less than 100.00% of C online submissions for Running Sum of 1d Array.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* ans = malloc(sizeof(int)*numsSize);
    ans[0] = nums[0];
    for (int i = 1; i < numsSize; i++){        
        ans[i] = ans[i-1] + nums[i];
    }
    *returnSize = numsSize;
    return ans;
}