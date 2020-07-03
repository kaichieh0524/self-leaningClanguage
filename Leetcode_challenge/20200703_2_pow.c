//  pow (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Pow(x, n).
// Memory Usage: 5.1 MB, less than 93.17% of C online submissions for Pow(x, n).

double myPow(double x, int n){
    if (n==0){return 1;}
    int sign = n;
    int index = 31;
    double  ans = x;
    
    bool* buffet = calloc(32, sizeof(bool));

    for (int i = 0; i < 32 && n != 0; i++) {
        buffet[i] = n % 2;
        n = n / 2;
        if (n == 0){break;}
    }
    // printf("The 32-bit of n:");
    // for (int j = 0; j < 32; j++) {
    //     printf("%d", buffet[31 - j]);
    // }
    while (buffet[index] != 1) {
        index--;
    }
    //printf("\nindex:%d",index);
    for (int k = 1 ; k < index + 1; k++) {
        ans *= ans;
        if (buffet[index - k] == 1) {
            ans = ans * x;
        }
    }
    //printf("\nans:%f", ans);
    if (sign > 0){
        return ans;
    }
    else if ( sign < 0){
        return 1/ans;
    }
    
    
    return 0;
}