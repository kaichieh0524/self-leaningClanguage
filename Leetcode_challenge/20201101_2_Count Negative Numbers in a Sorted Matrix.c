// Count Negative Numbers in a Sorted Matrix (easy)
// Runtime: 20 ms, faster than 70.92% of C online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 7.1 MB, less than 80.85% of C online submissions for Count Negative Numbers in a Sorted Matrix.



int countNegatives(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            if (grid[i][j]<0){
                ans++;
            }
        }
    }
    return ans;
}