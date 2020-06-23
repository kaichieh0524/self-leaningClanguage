// Happy Number (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Happy Number.
// Memory Usage: 5.1 MB, less than 59.19% of C online submissions for Happy Number.

int digit_square_sum(int num){
    int sum = 0;
    while (num != 0)
    {
        sum += (num%10)*(num%10);
        num /= 10;
    }
    return sum;
}

bool isHappy(int n){
    
    while ((n != 1)&&(n != 4))
    {
        n = digit_square_sum(n);
    }
    if (n ==1 ) {return 1;}
    return 0;
}