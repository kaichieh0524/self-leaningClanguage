// Set Matrix Zeroes (medium)
// Runtime: 44 ms, faster than 62.96% of C online submissions for Set Matrix Zeroes.
// Memory Usage: 10.5 MB, less than 90.91% of C online submissions for Set Matrix Zeroes.


typedef struct linkedlist {
    int row;
    int col;
    struct lindedlist* next;
}linkedlist;



void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
//         printf("origin matrix : \n\n");
//     for (int i = 0; i < matrixSize; i++) {
//         for (int j = 0; j < *matrixColSize; j++) {
//             printf(" %d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n-----------------------------------------------------------\n");
    
    linkedlist* location_0 = malloc(sizeof(linkedlist));
    linkedlist* cur = location_0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                linkedlist* temp = malloc(sizeof(linkedlist));
                cur->row = i;
                cur->col = j;
                cur->next = temp;
                cur = cur->next;
            }
        }
        
    }
    cur->row = -1;
    cur->col = -1;
    cur->next = NULL;
    cur = location_0;

    while (cur->next) {

        //printf("row : %d, col : %d\n", cur->row,cur->col);
        for (int i = 0; i < *matrixColSize; i++) {
            matrix[cur->row][i] = 0;
        }
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][cur->col] = 0;
        }
        cur = cur->next;
    }
    // printf("\n-----------------------------------------------------------\n");
    // printf("after replaced zero  : \n\n");
//     for (int i = 0; i < matrixSize; i++) {
//         for (int j = 0; j < *matrixColSize; j++) {
//             printf(" %d ", matrix[i][j]);
//         }
//         printf("\n");
//     }

}