// Sort Array By Parity (easy)
// Runtime: 28 ms, faster than 74.47% of C online submissions for Sort Array By Parity.
// Memory Usage: 9.4 MB, less than 98.80% of C online submissions for Sort Array By Parity.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int* ans = malloc(sizeof(int)*ASize);
    int i = 0;
    int start = 0;
    int end = ASize - 1;
    while(i < ASize){
        if (A[i] % 2 == 0){
            ans[start++] = A[i];
        }
        else{
            ans[end--] = A[i];
        }
        i++;
    }
    return ans;
}