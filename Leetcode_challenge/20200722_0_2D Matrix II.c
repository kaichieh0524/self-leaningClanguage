// 2D Matrix II (medium)
// Runtime: 140 ms, faster than 28.42% of C online submissions for Search a 2D Matrix II.
// Memory Usage: 8.6 MB, less than 80.00% of C online submissions for Search a 2D Matrix II.

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize == 0 || matrixColSize == 0){return 0;}
    int row = 0;
    while (row < matrixRowSize){
        if (matrix[row][0] == target ){return 1;}
        if (target == matrix[row][matrixColSize-1]){return 1;}
        if (matrix[row][0] < target && target < matrix[row][matrixColSize-1]){
            int left = 0;
            int right = matrixColSize - 1;
            
            while(left < right){
                int mid = (right + left)/2;
                if (matrix[row][mid] == target){return 1;}
                else if (matrix[row][mid] < target){left = mid;}
                else if (matrix[row][mid] > target){right = mid;}
                
                if (right-left == 1){
                    if (matrix[row][right]== target){return 1;}
                    if (matrix[row][left]== target){return 1;}
                    break;
                }
            }           
        
        }
    row += 1;
    }
    return 0;
}