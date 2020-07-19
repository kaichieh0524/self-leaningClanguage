// Divide Two Integers (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Divide Two Integers.
// Memory Usage: 5.2 MB, less than 37.04% of C online submissions for Divide Two Integers.

#define INFINITY  2147483647
#define nINFINITY  -2147483648

int divide(int dividend, int divisor){    
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;  
  
    long long int a = dividend, b = divisor, quotient = 0, temp = 0;     
    
    if (a<0){a*=-1;}
    if (b<0){b*=-1;}
    
    for (int i = 31; i >= 0; --i) { 
  
    if (temp + (b << i) <= a) { 
        temp += b << i; 
        quotient |= 1LL << i; 
        } 
    }
    printf("%d",sign*quotient);
    if (sign*quotient >= INFINITY || sign*quotient < nINFINITY){
        return INFINITY;
    }
    
    return sign*quotient;
}