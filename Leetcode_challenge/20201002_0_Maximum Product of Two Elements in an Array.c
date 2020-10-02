// Maximum Product of Two Elements in an Array (easy)
// Runtime: 24 ms, faster than 14.75% of C online submissions for Maximum Product of Two Elements in an Array.
// Memory Usage: 5.9 MB, less than 9.68% of C online submissions for Maximum Product of Two Elements in an Array.


int maxProduct(int* nums, int numsSize){
    int max = 0;
    for (int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if ( i == j){continue;}
            int n = (nums[i]-1)*(nums[j]-1);
            if (max < n){
                max = n;
            }
        }
    }
    return max;
}