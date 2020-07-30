// Kth Largest Element in an Array (medium)
// Runtime: 12 ms, faster than 65.95% of C online submissions for Kth Largest Element in an Array.
// Memory Usage: 5.9 MB, less than 75.00% of C online submissions for Kth Largest Element in an Array.
    
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findKthLargest(int* nums, int numsSize, int k){    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize-k];
}