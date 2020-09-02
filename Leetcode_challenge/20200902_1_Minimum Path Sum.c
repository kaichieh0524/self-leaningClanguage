// Minimum Path Sum (medium)
// Runtime: 24 ms, faster than 8.47% of C online submissions for Minimum Path Sum.
// Memory Usage: 7 MB, less than 50.85% of C online submissions for Minimum Path Sum.




int minPathSum(int** grid, int gridSize, int* gridColSize){
    
    int* temp = malloc(sizeof(int)* (gridColSize[0]+1));
    
    for (int i = 0; i < gridColSize[0]+1; i++){
        temp[i] = INT_MAX;
    }
    
    temp[1] = 0;
    
    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridColSize[0]; j++){
            temp[j+1] = fmin(temp[j+1],temp[j])+grid[i][j];
        }
    }
    
    return temp[gridColSize[0]];;
}
