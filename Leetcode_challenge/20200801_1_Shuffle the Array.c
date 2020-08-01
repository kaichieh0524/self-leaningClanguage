// Shuffle the Array (easy)
// Runtime: 16 ms, faster than 45.19% of C online submissions for Shuffle the Array.
// Memory Usage: 6.9 MB, less than 16.67% of C online submissions for Shuffle the Array.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int index1 = 0;
    int index2 = n;
    int* ans = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++){
        if(i%2==0){
            ans[i] = nums[index1++];
        }
        else{
           ans[i] = nums[index2++]; 
        }
    }
    return ans;
}