// Number of Islands (medium)
// Runtime: 12 ms, faster than 86.39% of C online submissions for Number of Islands.
// Memory Usage: 7.4 MB, less than 53.33% of C online submissions for Number of Islands.

void subroutine(int row, int col, char** grid, int gridSize, int* gridColSize){
    if (col >= *gridColSize || row >= gridSize || col < 0|| row < 0 || grid[row][col]=='0'){
        return;
    }
    if (grid[row][col]=='1'){grid[row][col]='0';}
    subroutine( row-1,  col,  grid,  gridSize,  gridColSize);
    subroutine( row,  col-1,  grid,  gridSize,  gridColSize);
    subroutine( row+1,  col,  grid,  gridSize,  gridColSize);
    subroutine( row,  col+1,  grid,  gridSize,  gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < *gridColSize; j ++){
            if (grid[i][j]=='1'){
                ans += 1;
                subroutine( i,  j,  grid,  gridSize,  gridColSize);
            }
        }
    }
    return ans;
}