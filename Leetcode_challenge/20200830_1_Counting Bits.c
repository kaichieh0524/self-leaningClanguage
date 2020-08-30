// Counting Bits (medium)
// Runtime: 36 ms, faster than 96.52% of C online submissions for Counting Bits.
// Memory Usage: 10.1 MB, less than 54.11% of C online submissions for Counting Bits.



int count_one(int n){
    if (n == 0){return 0;}
    if (n == 1){return 1;}
    if (n % 2 == 0){return count_one(n/2);}
    return count_one(n/2)+1;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int* ans = malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        ans[i] = count_one(i);
    }
    return ans;
}