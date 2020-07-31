// Kth Smallest Element in a Sorted Matrix (medium)
// Runtime: 60 ms, faster than 36.36% of C online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage: 8.4 MB, less than 100.00% of C online submissions for Kth Smallest Element in a Sorted Matrix.
// it should be optimized
    
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
     int index = 0;
    int list[matrixSize*(*matrixColSize)]; 
    if (matrixSize == 1) {return matrix[0][k-1];}
    printf(" %d  ",matrixSize*(*matrixColSize));
    
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < *matrixColSize; j++){
            list[index] = matrix[i][j];
            index += 1;
        }
    }
    qsort(list , matrixSize*(*matrixColSize), sizeof(int), cmpfunc);
    return list[k-1];
    
    
}