//Reverse Integer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 2147483647
#define min -2147483648

int reverse(int x){
    
    if (x==min || x==0){
        return 0; 
    } else{
   
    int y[10];
    int sign;
    double reverse = 0;
    int use_bits = 9;

    printf("origin number : %d\n", x);
    if (x > 0) {
        sign = 1;        
    }
    else {
        sign = -1;        
        x = -1 * x;
    }
    
    printf("sign : %d\n", sign);
    printf("decimal expression :");
    for (int i = 0; i < 10; i++) {
        y[i] = x% 10;
        x = (int) (x / 10);
        printf("%d", y[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (y[use_bits - i] != 0) {
            use_bits = use_bits - i+1;
            break;
        }
    }
    printf("\nuse bits : %d", use_bits);
        
    for (int i = 0 ; i< use_bits ; i++){
        reverse = reverse +y[i]*( pow (10,use_bits-i-1));        
    }
    
    printf("\nresult : %f", reverse);
    
    if (min<=reverse*sign && reverse*sign<max) {
        return ((int) reverse*sign);
    }
    else{
        return 0;
    }
   
}
}