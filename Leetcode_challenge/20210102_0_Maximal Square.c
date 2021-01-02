// Maximal Square
// Runtime: 16 ms, faster than 95.51% of C online submissions for Maximal Square.
// Memory Usage: 8.1 MB, less than 21.35% of C online submissions for Maximal Square.

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int** dp = malloc(sizeof(int*)*(matrixSize+1));
    
    for (int i = 0; i < matrixSize+1; i++){
        dp[i] = calloc(matrixColSize[0]+1, sizeof(int));
    }
    int max = 0;
    for (int i = 1; i <= matrixSize;i++){
        for (int j = 1; j <= matrixColSize[0];j++){
            if (matrix[i-1][j-1]=='1'){
                dp[i][j] = fmin(fmin(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]) + 1;
                max = fmax(max,dp[i][j]);
            }
        }
    }
    
    
    
    return max*max;
}