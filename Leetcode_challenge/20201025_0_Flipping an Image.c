// Flipping an Image (esay)
// Runtime: 12 ms, faster than 70.53% of C online submissions for Flipping an Image.
// Memory Usage: 6.9 MB, less than 77.89% of C online submissions for Flipping an Image.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = ASize;
    returnColumnSizes[0] = malloc(sizeof(int*)*ASize);
    returnColumnSizes[0] = AColSize;
    
    for (int i = 0; i < ASize; i++){
        for (int j = 0; j < AColSize[i]/2; j++){
            int temp = A[i][j];
            A[i][j] = A[i][AColSize[i]-1-j];
            A[i][AColSize[i]-1-j] = temp;

        }
    }
    
    
    for (int i = 0; i < ASize; i++){
        for (int j = 0; j < AColSize[i]; j++){
           A[i][j] = A[i][j] ? 0 : 1;
        }
    }
    
    
    
    return A;
}