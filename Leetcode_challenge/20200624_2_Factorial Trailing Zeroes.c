// Factorial Trailing Zeroes (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Factorial Trailing Zeroes.
// Memory Usage: 5.1 MB, less than 85.96% of C online submissions for Factorial Trailing Zeroes.
// key idea just count the number of 5 in integer factorization, because 10 = 2 * 5 and even always enough.


int trailingZeroes(int n){
    
    if (n == 0) { return 0; }    
    int ans = 0;
    for (int i = 1; ;i++)
    {
        ans = ans + ((int) n / 5);
        n /= 5;
        if (n == 0) { break; }
    }
    return ans;
}