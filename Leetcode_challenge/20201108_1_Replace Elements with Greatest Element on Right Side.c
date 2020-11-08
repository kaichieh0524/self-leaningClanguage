// Replace Elements with Greatest Element on Right Side (easy)
// Runtime: 52 ms, faster than 91.07% of C online submissions for Replace Elements with Greatest Element on Right Side.
// Memory Usage: 12.5 MB, less than 58.93% of C online submissions for Replace Elements with Greatest Element on Right Side.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){   
    *returnSize = arrSize;
    int max = arr[arrSize-1];
    arr[arrSize - 1] = - 1;
    for (int i = arrSize - 2; i >= 0; i--){
        int temp = arr[i];
        arr[i] = max;
        if (max < temp){
            max = temp;
        }
    }
    return arr;
}