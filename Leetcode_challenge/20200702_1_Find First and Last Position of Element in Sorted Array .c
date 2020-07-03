// Find First and Last Position of Element in Sorted Array (medium)
// Runtime: 8 ms, faster than 81.78% of C online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 7.2 MB, less than 8.82% of C online submissions for Find First and Last Position of Element in Sorted Array.

int binarysearch(int* nums, int numsSize, int target, int left, int right)
{
    
    int l = 0;
    int r = numsSize - 1;
    int mid = (l + r) / 2;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return 1;
        }
        else if (nums[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int binarysearchfirst(int* nums, int numsSize, int target, int left, int right, int* ans)
{
    int mid = (right + left) / 2;
    int l = 0;
    int r = numsSize - 1;
    if (mid == 0 && nums[mid]==target) {return mid;}
    if (mid == 0 && nums[mid]!=target) {mid=mid+1;}
    
    while (nums[mid-1] == target || nums[mid] != target ) {

        mid = (l + r) / 2;
        if (mid == 0) {return mid;}
        if (nums[mid] < target) {
            l = mid + 1 < numsSize ? mid + 1 : numsSize - 1;           
        }
        else {
            r = mid - 1 > 0 ? mid - 1 : 0;
        }
    }
    return mid;
}

int binarysearchsecond(int* nums, int numsSize, int target, int left, int right, int* ans)
{
    int mid = (right + left) / 2 ;
    int l = 0;
    int r = numsSize - 1;
    if (mid == numsSize-1 && nums[mid]==target){return mid;}

    while (nums[mid + 1] == target || nums[mid] !=target) {

        mid = (l + r) / 2;
        if (mid == numsSize-1){return mid;}

        if (nums[mid] > target) {
            r = mid - 1 > 0 ? mid - 1 : 0;
           
        }
        else {
            l = mid + 1 < numsSize ? mid + 1 : numsSize - 1;
        }
        
    }
    return mid;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
     int* ans = malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;
    if (binarysearch(nums, numsSize, target, 0, numsSize - 1)==-1){
        return ans;
    }
    if (nums[0]==nums[numsSize-1]){
        ans[0] = 0;
        ans[1] = numsSize-1;
        return ans;
        
    }
    
     ans[0] = binarysearchfirst(nums, numsSize, target, 0, numsSize - 1, ans);
     ans[1] = binarysearchsecond(nums, numsSize, target, 0, numsSize - 1, ans);

     printf("\nans[0] : %d\n", ans[0]);
     printf("\nans[1] : %d\n", ans[1]);
    
    
    
    
    return ans;
}