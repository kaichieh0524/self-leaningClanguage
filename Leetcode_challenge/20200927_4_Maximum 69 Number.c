// Maximum 69 Number (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Maximum 69 Number.
// Memory Usage: 5.9 MB, less than 5.19% of C online submissions for Maximum 69 Number.


int maximum69Number (int num){
    int n =  log10(num);
    int y = pow(10,n);
    while(y!=0){
        int remain = num % (y*10);
        remain /= y;
        if(remain == 6){
            return 3*y+num;
        }
        y /= 10;
    }
    return num;
}