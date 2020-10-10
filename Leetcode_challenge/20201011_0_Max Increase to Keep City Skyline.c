// Max Increase to Keep City Skyline (medium)
// Runtime: 8 ms, faster than 73.53% of C online submissions for Max Increase to Keep City Skyline.
// Memory Usage: 5.9 MB, less than 100.00% of C online submissions for Max Increase to Keep City Skyline.



int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    int* vertical = malloc(sizeof(int)*gridSize);
    int* horizontal = malloc(sizeof(int)*gridSize);
    
    for (int i = 0; i < gridSize; i++){
        int max = 0;
        for (int j = 0; j < gridColSize[i]; j++){
            max = grid[i][j]> max ? grid[i][j] : max;
            }
        horizontal[i] = max;
        max = 0;
        for (int j = 0; j < gridSize; j++){
            max = grid[j][i]> max ? grid[j][i] : max;
            }
        vertical[i] = max;
        }
        
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            ans +=  fmin(horizontal[i],vertical[j]) - grid[i][j];
        }
    }
    
    
    return ans;
}
