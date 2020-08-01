// Game of Life (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Game of Life.
// Memory Usage: 5.7 MB, less than 50.00% of C online submissions for Game of Life.
// it should be modified to in-place

int searchneighbor(int** board, int boardSize, int* boardColSize, int row, int col){
   int count = 0;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if ( i == 0 && j == 0){continue;}
            if ( row + i < 0 || col + j < 0 || row + i >= boardSize || col + j >= *boardColSize){continue;}
            if (board[row+i][col+j]==1){count+=1;}
        }
    }
    return count;
}


void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (boardSize == 0 || *boardColSize == 0){return;}
    int temp[boardSize][*boardColSize];
    memset(temp, 0, sizeof(int) * boardSize * (*boardColSize));
    int count;
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            count = searchneighbor( board,  boardSize,  boardColSize, i, j);
            if (count < 2) {temp[i][j]=0;}
            else if ((board[i][j] == 1 && count == 2) ||(board[i][j] == 1 && count == 3)) {temp[i][j]=1;}
            else if ( count > 3) {temp[i][j]=0;}
            else if (board[i][j] == 0 && count == 3) {temp[i][j]=1;}
        }
    }
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            board[i][j] = temp[i][j];
        }
    }
}