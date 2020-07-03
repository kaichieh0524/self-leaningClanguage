// Rotate Image (medium)
// Runtime: 8 ms, faster than 16.97% of C online submissions for Rotate Image.
// Memory Usage: 6 MB, less than 50.96% of C online submissions for Rotate Image.

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void transpose_square(int** matrix,int matrixSize) {

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            swap( &matrix[i][j], &matrix[j][i]);
        }
    }
}
void reverse_column(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j <=  (matrixSize-1) / 2; j++) {
            swap(&matrix[i][j], &matrix[i][matrixSize-1-j]);
        }
    }
}


void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    transpose_square(matrix, matrixSize);

    printf("\n------------------------------\n");
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    reverse_column(matrix, matrixSize);

    printf("\n------------------------------\n");

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n------------------------------\n");
}