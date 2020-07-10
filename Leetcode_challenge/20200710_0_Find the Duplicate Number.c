// Find the Duplicate Number (medium)
// Runtime: 28 ms, faster than 33.26% of C online submissions for Find the Duplicate Number.
// Memory Usage: 6.6 MB, less than 80.77% of C online submissions for Find the Duplicate Number.
// the complexity is O(nlogn)

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 1; i < numsSize; i++){
        if(nums[i]==nums[i-1]){return nums[i];}
    }
    return 0;
}