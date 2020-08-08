// Surrounded Regions (medium)
// Runtime: 32 ms, faster than 68.31% of C online submissions for Surrounded Regions.
// Memory Usage: 10.7 MB, less than 41.55% of C online submissions for Surrounded Regions.



void* DFS(char** board,  int boardSize, int* boardColSize, int i, int j){
    if ( i < 0 || i >= boardSize || j >= *boardColSize || j < 0 || board[i][j]=='X'|| board[i][j]=='1'){return;}
    if (board[i][j]=='O'){board[i][j]='1';}
    DFS(board, boardSize, boardColSize,   i+1, j);
    DFS(board, boardSize, boardColSize,   i-1, j);
    DFS(board, boardSize, boardColSize,   i, j+1);
    DFS(board, boardSize, boardColSize,   i, j-1);    

}


void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0 ){return NULL;}
    //   for (int i = 0; i < boardSize; i++){
    //     for (int j = 0; j < *boardColSize; j++){
    //         printf(" %c ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n-----------------------------------------------------------\n");

  
    for (int i = 0; i < *boardColSize; i++){
        DFS(board, boardSize, boardColSize,   0, i);
        DFS(board, boardSize, boardColSize,   boardSize-1, i);
    }
    for (int i = 0; i < boardSize; i++){
        DFS(board, boardSize, boardColSize,   i, 0);
        DFS(board, boardSize, boardColSize,   i, *boardColSize-1);
    }
    // for (int i = 0; i < boardSize; i++){
    //     for (int j = 0; j < *boardColSize; j++){
    //         printf(" %c ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            if (board[i][j]=='1'){board[i][j]='O';}
            else if (board[i][j]=='O'){board[i][j]='X';}
        }        
    }
    // printf("\n-----------------------------------------------------------\n");
    // for (int i = 0; i < boardSize; i++){
    //     for (int j = 0; j < *boardColSize; j++){
    //         printf(" %c ", board[i][j]);
    //     }
    //     printf("\n");
    // }
}