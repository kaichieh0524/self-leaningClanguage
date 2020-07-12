// Unique Paths (medium)
// Runtime: 4 ms, faster than 15.38% of C online submissions for Unique Paths.
// Memory Usage: 5.1 MB, less than 82.76% of C online submissions for Unique Paths.
    
int binomialCoeff(int n, int k) 
{ 
    long res = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
      
    return res; 
} 
int uniquePaths(int m, int n){
   return binomialCoeff(m+n-2,m-1);
}