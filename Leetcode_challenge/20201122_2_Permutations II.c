// Permutations II (medium)
// Runtime: 20 ms, faster than 97.78% of C online submissions for Permutations II.
// Memory Usage: 9.1 MB, less than 91.11% of C online submissions for Permutations II.

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }    
    return n*factorial(n-1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int* count, int** ans, int* used, int* cur, int step, int numsSize, int* nums){
    if (step == numsSize){
        ans[*count] = malloc(sizeof(int)*numsSize);
        for (int i = 0; i < numsSize; i++){
            ans[*count][i] = cur[i];
        }
        (*count)++;
        return;
    }
    for (int i = 0; i < numsSize; i++){
        if(used[i]){
            continue;
        }
        if( i > 0 && nums[i]==nums[i-1] && !used[i-1]){
            continue;
        }
        used[i] = 1;
        cur[step] = nums[i];
        dfs(count, ans, used, cur, step + 1, numsSize, nums);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
  
    int** ans = malloc(sizeof(int*)*factorial(numsSize));
    int* used = calloc(numsSize,sizeof(int));
    int* cur = malloc(sizeof(int)*numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    dfs(returnSize, ans, used, cur, 0, numsSize, nums);
    
    returnColumnSizes[0] = malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        returnColumnSizes[0][i] = numsSize;
    }
    printf("%d", *returnSize);
    return ans;
}





 