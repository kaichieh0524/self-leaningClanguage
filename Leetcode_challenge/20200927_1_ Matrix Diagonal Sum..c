// Runtime: 16 ms, faster than 89.09% of C online submissions for Matrix Diagonal Sum.
// Memory Usage: 6.9 MB, less than 5.45% of C online submissions for Matrix Diagonal Sum.



int diagonalSum(int** mat, int matSize, int* matColSize){
    int ans = 0;
    for (int i = 0; i < matSize; i++){
        ans += mat[i][i] + mat[i][matSize-i-1];
    }
    printf("%d", ans);
    if( matSize  % 2 != 0){
        ans -= mat[(matSize+1)/2 - 1][(matSize+1)/2 - 1];
    }
    return ans;
}