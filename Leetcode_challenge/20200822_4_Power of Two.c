// Power of Two (easy)
// Runtime: 4 ms, faster than 43.56% of C online submissions for Power of Two.
// Memory Usage: 5.1 MB, less than 74.00% of C online submissions for Power of Two.


bool isPowerOfTwo(int n){
    if (n == 0 || n < 0){return 0;}
    if (n == 1){return 1;}
    while (n > 1){
        if (n%2!=0){return 0;}
        else{
            n = n/2;
        }
    }
    return 1;
}