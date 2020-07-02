// Rotated Sorted Array (medium)
// Runtime: 4 ms, faster than 67.97% of C online submissions for Search in Rotated Sorted Array.
// Memory Usage: 5.5 MB, less than 94.96% of C online submissions for Search in Rotated Sorted Array.


int binarysearch(int* nums,int left, int right,int target)
{
   while (left <= right)
    {
        int mid = (right + left) / 2 ;
        if (nums[mid] == target) {
            //printf("the ans index is :%d", mid);
            return mid;
        }
         if (nums[mid] >= nums[left] && target < nums[mid] && nums[left] <= target) {
            return binarysearch(nums, left, mid - 1, target);
        }
        else if (nums[mid] >= nums[left] && (target > nums[mid] || nums[left] > target)) {
            return binarysearch(nums, mid + 1, right, target);
        }
        else if (nums[mid] < nums[left] && target > nums[mid] && nums[right] >= target) {
            return binarysearch(nums, mid + 1, right, target);
        }
        else {
            return binarysearch(nums, left, mid - 1, target);
        }
    }
    return -1;
}


int search(int* nums, int numsSize, int target){    
    return binarysearch(nums, 0, numsSize - 1, target);
}