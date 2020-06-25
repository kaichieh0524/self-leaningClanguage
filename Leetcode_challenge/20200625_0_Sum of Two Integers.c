// Sum of Two Integers (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Sum of Two Integers.
// Memory Usage: 5.2 MB, less than 32.14% of C online submissions for Sum of Two Integers.

int getSum(int a, int b){
    unsigned int carry = 1;
    while (carry !=0){
        
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

