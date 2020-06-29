// implement strStr (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 0 ms, faster than 100.00% of C online submissions for Implement strStr().
// Memory Usage: 5.6 MB, less than 50.21% of C online submissions for Implement strStr().
    
int strStr(char * haystack, char * needle){
    
    
    
    if (strlen(needle) == 0 ){
        return 0;
    }
    
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    
    if (l1<l2){
        return -1;
    }
    
    for (int i = 0 ; i <= l1-l2 ; i++){
        int j;
        for (j=0 ; j<l2 ; j++){
            if (haystack[i+j] != needle[j]){
                break;
            }
        }   
        if (j==l2){
            return i;
            }
        
    }
    return -1;      
}