// Decompress Run-Length Encoded List (easy)
// Runtime: 28 ms, faster than 96.98% of C online submissions for Decompress Run-Length Encoded List.
// Memory Usage: 10.2 MB, less than 37.91% of C online submissions for Decompress Run-Length Encoded List.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int* ans = malloc(sizeof(int)*10240);
    *returnSize = 0;
    int len = numsSize / 2;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < nums[2*i]; j++){
            ans[(*returnSize)++] = nums[2*i+1];
        }
    }
    return ans;
}