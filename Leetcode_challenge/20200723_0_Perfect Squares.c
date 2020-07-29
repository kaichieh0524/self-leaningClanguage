// Perfect Squares (medium)
// Runtime: 56 ms, faster than 64.49% of C online submissions for Perfect Squares.
// Memory Usage: 8.2 MB, less than 20.00% of C online submissions for Perfect Squares.

int numSquares(int n){
    if (n<=1){return n;}
    int* ans = malloc(sizeof(int)*(n+1));
    ans[0] = 0;
    
    for (int i = 1; i <= n; i++){
        
        int min = i, square = 1;
        for (int j = 1; j*j <= i; j++){
            int temp = 1 + ans[i-j*j];
            if (temp < min){
                min = temp;
            }
        }
        ans[i] = min;
    }
    int solution = ans[n];
    free(ans);
    return solution;
}

