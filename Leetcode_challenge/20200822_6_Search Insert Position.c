// Search Insert Position (easy)
// Runtime: 8 ms, faster than 29.15% of C online submissions for Search Insert Position.
// Memory Usage: 5.7 MB, less than 48.96% of C online submissions for Search Insert Position.



int searchInsert(int* nums, int numsSize, int target){
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == target){return i;}
        if (nums[i] > target){return i;}
    }
    return numsSize;
}