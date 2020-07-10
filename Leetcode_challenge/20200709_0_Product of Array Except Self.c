// Product of Array Except Self (medium)
// Runtime: 40 ms, faster than 99.62% of C online submissions for Product of Array Except Self.
// Memory Usage: 14.1 MB, less than 12.61% of C online submissions for Product of Array Except Self.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    if(numsSize == 0) {returnSize = 0; return NULL;}
    *returnSize = numsSize;
    int* ans = malloc(sizeof(int)*numsSize);
    
    int* L1 = malloc(sizeof(int)*numsSize);
    int* L2 = malloc(sizeof(int)*numsSize);    
    int prod1 = 1;
    int prod2 = 1;
    
    for (int i = 0; i < numsSize; i++) {
        L1[i] = prod1;
        L2[numsSize - 1 - i] = prod2;
        prod1 *= nums[i];
        prod2 *= nums[numsSize - 1 - i];

    }
    
      for (int i = 0; i < numsSize; i++) {
        ans[i] = L1[i]*L2[i];

    }
//      printf("L1 :");
//     for (int i = 0; i < numsSize; i++) {
        
//         printf("%d,", L1[i]);

//     }

//     printf("\n------------------------------------------------------------\n");
//      printf("L2 :");
//     for (int i = 0; i < numsSize; i++) {

//         printf("%d,", L2[i]);

//     }
//     printf("\n------------------------------------------------------------\n");
//      printf("ans :");
//     for (int i = 0; i < numsSize; i++) {

//         printf("%d,", ans[i]);

//     }
    return ans;
}