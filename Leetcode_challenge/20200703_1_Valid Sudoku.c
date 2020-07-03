// Valid Sudoku (medium)
// Runtime: 28 ms, faster than 7.28% of C online submissions for Valid Sudoku.
// Memory Usage: 5.7 MB, less than 31.92% of C online submissions for Valid Sudoku.

bool findrepeatrow(char** matrix)
{
    bool* temp = calloc(9, sizeof(bool));
    for (int i = 0; i < 9 ; i++) {
        memset(temp, 0, 9);        
        for (int j = 0; j < 9; j++) {
            
            if (isdigit(matrix[i][j])) {
                int t = (int) matrix[i][j] % 48-1;
                if (temp[t] == 1) {
                    return 0;
                }
                else {
                    temp[t] = 1;
                }                
            }            
        }
    }
    free(temp);
    return 1;

}

bool findrepeatcolumn(char** matrix)
{
    bool* temp = calloc(9, sizeof(bool));
    for (int i = 0; i < 9; i++) {
        memset(temp, 0, 9);
        for (int j = 0; j < 9; j++) {

            if (isdigit(matrix[j][i])) {
                int t = (int)matrix[j][i] % 48 - 1;
                if (temp[t] == 1) {
                    return 0;
                }
                else {
                    temp[t] = 1;
                }
            }
        }
    }
    free(temp);
    return 1;

}

bool findrepeat3_3(char** matrix)
{
    bool* temp = calloc(9, sizeof(bool));
    for (int i = 0; i < 9; i = i + 3) {        
        for (int j = 0; j < 9; j = j + 3) {
            memset(temp, 0, 9);
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {

                    if (isdigit(matrix[i+k][j+l])) {
                        int t = (int)matrix[i+k][j+l] % 48 - 1;
                        if (temp[t] == 1) {
                            return 0;
                        }
                        else {
                            temp[t] = 1;
                        }
                    }
                }
            }       
        }
    }
    free(temp);
    return 1;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int ans = findrepeatrow(board);
    if (ans == 0) 
    {
        printf("there are repeated elements in row\n");
        return 0;
    }
    int ans1 = findrepeatcolumn(board);
    if (ans1 == 0)
    {
        printf("there are repeated elements in column\n");
        return 0;
    }
    int ans2 = findrepeat3_3(board);
    if (ans2 == 0)
    {
        printf("there are repeated elements in submatrix 3*3\n");
        return 0;
    }
    return 1;
}