// Maximum Product Subarray (medium)
// Runtime: 8 ms, faster than 45.45% of C online submissions for Maximum Product Subarray.
// Memory Usage: 5.9 MB, less than 100.00% of C online submissions for Maximum Product Subarray.

int maxProduct(int* nums, int numsSize){
    int maximum = nums[0];
    int minimum = nums[0];
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++){
        int temp = fmax(nums[i],fmax(nums[i]*maximum,nums[i]*minimum));
        minimum = fmin(nums[i],fmin(nums[i]*maximum,nums[i]*minimum));
        maximum = temp;
        ans = fmax(ans,maximum);
    }
    return ans;
}
