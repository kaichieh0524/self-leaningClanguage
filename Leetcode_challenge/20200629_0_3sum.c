// 3Sum (medium)
// Runtime: 132 ms, faster than 77.24% of C online submissions for 3Sum.
// Memory Usage: 29.6 MB, less than 18.52% of C online submissions for 3Sum.

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*20000);
    int total = 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize; i++){
        if( i != 0 && nums[i] == nums[i-1]) {continue;}
        int j = i + 1;
        int k = numsSize - 1;
        while(j < k)
        {
            if(nums[i]+nums[j]+nums[k] == 0)
            {
                ans[total] = malloc(sizeof(int)*3);
                ans[total][0] = nums[i];
                ans[total][1] = nums[j];
                ans[total][2] = nums[k];
                total++;
                j++;
                while(j < k && nums[j] == nums[j-1]){j++;}
            }            
            else if(nums[i]+nums[j]+nums[k] < 0){j++;}
            else {k--;}
        }
    }
    
    
    *returnSize = total;
    *returnColumnSizes = malloc(sizeof(int)*total);
    for (int i = 0 ; i < total;  i++){
        returnColumnSizes[0][i] = 3;
    }
    
    return ans;
}