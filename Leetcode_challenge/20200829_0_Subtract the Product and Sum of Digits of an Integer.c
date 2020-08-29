// Subtract the Product and Sum of Digits of an Integer (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Subtract the Product and Sum of Digits of an Integer.
// Memory Usage: 5.1 MB, less than 77.62% of C online submissions for Subtract the Product and Sum of Digits of an Integer.


int subtractProductAndSum(int n){
    int prod = 1;
    int sum = 0;
    while (n != 0){        
        prod *= (n % 10);
        sum += (n % 10);
        n /= 10;
    }
    return prod-sum;
}