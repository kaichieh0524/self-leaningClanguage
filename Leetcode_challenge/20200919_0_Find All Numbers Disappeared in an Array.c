// Find All Numbers Disappeared in an Array (easy)
// Runtime: 92 ms, faster than 96.94% of C online submissions for Find All Numbers Disappeared in an Array.
// Memory Usage: 17.2 MB, less than 46.29% of C online submissions for Find All Numbers Disappeared in an Array.



void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* ans = malloc(numsSize*sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != nums[nums[i]-1] ){
            swap(&nums[i],&nums[nums[i]-1]);
            i--;
        }
    }

    for (int i = 0; i < numsSize; i++){
        if (nums[i] != i + 1){
            ans[(*returnSize)++] = i + 1;
        }
    }
    return ans;
}