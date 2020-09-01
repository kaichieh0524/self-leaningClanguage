// Daily Temperatures (medium)
// Runtime: 136 ms, faster than 100.00% of C online submissions for Daily Temperatures.
// Memory Usage: 23.7 MB, less than 11.67% of C online submissions for Daily Temperatures.
// using stack to store the descending nums


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* ans = calloc(TSize,sizeof(int));
    int* temp = calloc(TSize,sizeof(int));
    *returnSize = TSize;
    int k = 0;
    for (int i = 0; i < TSize; i++){
        
        while(k!=0 && T[i] > T[temp[k-1]]){
            ans[temp[k-1]] = i - temp[k-1];
            k--;
        }
        temp[k++] = i;
    }
    
    return ans;
}