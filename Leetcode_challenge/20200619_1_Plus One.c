// Plus One (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Runtime: 0 ms, faster than 100.00% of C online submissions for Plus One.
// Memory Usage: 5.4 MB, less than 94.29% of C online submissions for Plus One.
// Note : use calloc the value is initialized as 0
int* plusOne(int* digits, int digitsSize, int* returnSize){
   
    if(digitsSize==0){
        *returnSize = 1;
        int* ans= calloc(1,sizeof(int));
        ans[0]=1;
        return ans;
    }
    
    
    
	for (int i=digitsSize-1;i>=0;i--){
        
        if (digits[i]<9){
            digits[i]=digits[i]+1;
            break;
        }
        else
        {
            digits[i]=0 ; 
        }
    }
    
    if (digits[0]==0){
        *returnSize = digitsSize+1;
        int* ans = calloc(digitsSize+1,sizeof(int));
        ans[0]=1;
        return ans;
    }
    else
    {
         *returnSize = digitsSize;
    }
	
	
    return digits;
}