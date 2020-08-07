// Increasing Triplet Subsequence (medium)
// Runtime: 4 ms, faster than 92.54% of C online submissions for Increasing Triplet Subsequence.
// Memory Usage: 6 MB, less than 100.00% of C online submissions for Increasing Triplet Subsequence.


bool increasingTriplet(int* nums, int numsSize){
    int first = INFINITY;
    int second = INFINITY;
    
    for (int i = 0; i < numsSize; i++){
        if ( nums[i] <first ){
            first = nums[i];
        }
        if (nums[i] > first){
            second = fmin(second,nums[i]);
        }
        if (nums[i] > second){
            return 1;
        }
    }

    return 0;
}