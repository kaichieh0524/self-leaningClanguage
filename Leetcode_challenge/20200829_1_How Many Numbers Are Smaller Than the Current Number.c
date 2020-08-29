// How Many Numbers Are Smaller Than the Current Number (easy)
// Runtime: 8 ms, faster than 98.40% of C online submissions for How Many Numbers Are Smaller Than the Current Number.
// Memory Usage: 6.7 MB, less than 9.38% of C online submissions for How Many Numbers Are Smaller Than the Current Number.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0){return NULL;}
    int accuml = 0;
    *returnSize = numsSize;
    int* ans = malloc(sizeof(int)*(*returnSize));
    int* record = calloc(101,sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        record[nums[i]] += 1;
    }
    for (int i = 0; i < 101; i++){
        if (record[i]==0){continue;}
        int temp = record[i];
        record[i] = accuml;
        accuml += temp;
    }
    for (int i = 0; i < numsSize; i++){
        ans[i] = record[nums[i]];
    }
    return ans;
}