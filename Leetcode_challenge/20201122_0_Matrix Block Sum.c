// Matrix Block Sum (medium)
// Runtime: 32 ms, faster than 81.25% of C online submissions for Matrix Block Sum.
// Memory Usage: 10.8 MB, less than 50.00% of C online submissions for Matrix Block Sum.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes){
   
    *returnSize = matSize;
    returnColumnSizes[0] = malloc(sizeof(int)*matSize);
    for (int i = 0; i < matSize; i++){
        returnColumnSizes[0][i] = matColSize[0];
    }
    int dp[matSize+1][matColSize[0]+1];
    for (int i = 0; i <= matSize; i++){
        for (int j = 0; j <= matColSize[0]; j++){
            dp[i][j] = 0;            
        }
    }    
    for (int i = 1; i <= matSize; i++){
        for (int j = 1; j <= matColSize[0]; j++){
            dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];            
        }
    }
    for (int i = 1; i <= matSize; i++){
        for (int j = 1; j <= matColSize[0]; j++){
            int a = (j-K) > 0 ? j-K : 1;
            int b = (j+K) > matColSize[0] ? matColSize[0] : j+K;
            int c = (i-K) > 0 ? i-K : 1;
            int d = (i+K) > matSize ? matSize: i+K;            
            mat[i-1][j-1] = dp[d][b] - dp[d][a-1] - dp[c-1][b] + dp[c-1][a-1];
        }
    }  

    return mat;
}
