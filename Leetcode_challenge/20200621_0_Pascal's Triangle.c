// Pascal's Triangle (easy)

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Runtime: 0 ms, faster than 100.00% of C online submissions for Pascal's Triangle.
// Memory Usage: 5.8 MB, less than 15.22% of C online submissions for Pascal's Triangle.

int binomialCoeff(int n, int k) 
{ 
    int res = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
      
    return res; 
} 



int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    int** ans = (int**)malloc(sizeof(int*)*numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    
    for (int i = 0 ; i < numRows ; i++ ){
        ans[i] = malloc(sizeof(int)*(i+1));
        returnColumnSizes[0][i] = i + 1;
        for (int j = 0 ; j< i+1 ;j++){
            ans[i][j] = binomialCoeff(i,j);
        }
    }
    
    return ans;

}
