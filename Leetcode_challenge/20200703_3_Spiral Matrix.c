// Spiral Matrix (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Spiral Matrix.
// Memory Usage: 5.4 MB, less than 79.27% of C online submissions for Spiral Matrix.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize==0 || *matrixColSize==0){*returnSize=0;return NULL;}
    int* ans = calloc(matrixSize*(*matrixColSize),sizeof(int));
    *returnSize = matrixSize*(*matrixColSize);   
    int a = 0, b=0,c=matrixSize,d=*matrixColSize;
    int index = 0;
    
    while (a < c && b < d) {
        for (int i = b; i < d; i++) {
            printf("%d", matrix[a][i]);
            ans[index] = matrix[a][i];
            index++;
        }
        a++;
        for (int i = a; i < c; i++) {
            printf("%d", matrix[i][d-1]);
            ans[index] = matrix[i][d-1];
            index++;
        }
        d--;
        if (a < c) {
            for (int i = d-1; i >= b; i--) {
                printf("%d", matrix[c-1][i]);
                ans[index] = matrix[c-1][i];
                index++;
            }
            c--;
        }
        if (b < d) {
            for (int i = c-1; i >= a; i--) {
                printf("%d", matrix[i][b]);
                ans[index] = matrix[i][b];
                index++;
            }
            b++;
        }
    }
    return ans;
}
