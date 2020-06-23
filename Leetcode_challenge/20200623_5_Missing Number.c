// Missing Number (easy)
// Runtime: 16 ms, faster than 89.37% of C online submissions for Missing Number.
// Memory Usage: 6.3 MB, less than 53.74% of C online submissions for Missing Number.

int missingNumber(int* nums, int numsSize){
    int ans = 0;
    
    for (int i = 0 ; i < numsSize ; i++)
    {
        ans = ans - nums[i] + (i+1);
    }
    return ans;
}