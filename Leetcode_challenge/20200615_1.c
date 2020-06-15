// Palindrome Number (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#define max_len 11



bool isPalindrome(int x){
    int flag;
    bool ans = true;    
    int L[11];
    
    if (x<0){
        return false;
    }else if (x==0){
        return true;
    }else{
        printf("decimal expression : ");
        for (int i = 0; i < max_len; i++) {
            L[i] = x % 10;
            x = x / 10;
            printf("%d", L[i]);
            if (i == max_len - 1) {
                for (int j = max_len-1 ; j >= 0; j--) {
                            if (L[j] != 0) {
                                flag = j;
                                break;
                            }


                }
             printf("\nflag : %d", flag);
                for (int k = 0; k <flag; k++) {
                 if (L[k] != L[flag]) {
                     printf("\nNot Palindrome Number");
                     ans = false;
                 }
                 i++;
                 flag--;
                }
            }
        }

        printf("\nanswer : %d", ans);
        return ans;
    
    }
}