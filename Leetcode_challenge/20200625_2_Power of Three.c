// Power of Three (easy)
// Runtime: 12 ms, faster than 75.20% of C online submissions for Power of Three.
// Memory Usage: 6.2 MB, less than 5.67% of C online submissions for Power of Three.
// key idea : use the log, but it need to consider the float error.
bool isPowerOfThree(int n){
    if (n==0){return 0;}
    double a = (log(n) / log(3));
    int b = (int) a;        
    if ( n  == pow(3,b) || n == pow(3,b+1)){return 1;}
    return 0;
}