// Merge Intervals (medium)
// Runtime: 20 ms, faster than 56.02% of C online submissions for Merge Intervals.
// Memory Usage: 7.5 MB, less than 90.96% of C online submissions for Merge Intervals.


int compare(const void* v1, const void* v2) {
    if (((int**)v1)[0][0] == ((int**)v2)[0][0]){
        return ((int**)v1)[0][1] - ((int**)v2)[0][1];
    }
    return ((int**)v1)[0][0] - ((int**)v2)[0][0];
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(intervalsSize == 0){ return NULL;}
    int** ans = malloc(sizeof(int*)*intervalsSize);    
    qsort(intervals, intervalsSize, sizeof(intervals[0]), compare);       
    // for (int i = 0; i < intervalsSize; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         printf(" %d ", intervals[i][j]);
    //     }
    //     printf("\n");
    // }
    
    int index = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[index][1] >= intervals[i][0] && i != 0) {
            intervals[index][1] = fmax(intervals[index][1], intervals[i][1]);            
            ans[*returnSize-1][0] = intervals[index][0];
            ans[*returnSize-1][1] = intervals[index][1];            
        }
        else {
            index = i; 
            printf("%d", *returnSize);
            ans[*returnSize] = malloc(sizeof(int) * 2);
            ans[*returnSize][0] = intervals[index][0];
            ans[*returnSize][1] = intervals[index][1];            
            *returnSize += 1;
            
        }
    }
    returnColumnSizes[0] = malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        returnColumnSizes[0][i] = 2;
    }
    
    
    return ans;
}


