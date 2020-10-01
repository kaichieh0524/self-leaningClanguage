// Cells with Odd Values in a Matrix (easy)
// Runtime: 4 ms, faster than 86.30% of C online submissions for Cells with Odd Values in a Matrix.
// Memory Usage: 6.2 MB, less than 5.48% of C online submissions for Cells with Odd Values in a Matrix.



int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int count = 0;
    int** matrix = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        matrix[i] = calloc(m,sizeof(int));
    }

    for (int i = 0; i < indicesSize; i++){
        for (int j = 0; j < m; j++){
            matrix[indices[i][0]][j]++;
        }
        for (int j = 0; j < n; j++){
            matrix[j][indices[i][1]]++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(matrix[i][j] % 2 == 1){
                count++;
            }
            //printf(" %d ",matrix[i][j]);
        }
        //printf("\n");
    }
    return count;
}