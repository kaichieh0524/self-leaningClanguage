// Longest Common Prefix (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>


//   Runtime: 0 ms, faster than 100.00% of C online submissions for Longest Common Prefix.
// Memory Usage: 5.6 MB, less than 30.62% of C online submissions for Longest Common Prefix.  



char* longestCommonPrefix(char** strs , int strsSize) {
    char* ans;         
    int counter = -1;
    int flag = 0;
    
    if(strsSize <= 0){   
        return "";
    }
    if(strsSize==1){
        return strs[0];
    }
    
    ans = strs[0];
    
    while(flag!=1){
        counter = counter +1;
        for (int i=1 ; i<strsSize ; i++){
            if (ans[counter] != strs[i][counter] || ans[counter]=='\0' || strs[i][counter]=='\0'){
                flag = 1;
                printf("%d",counter);
                break;
            }
        }
        
    }
    ans[counter]='\0';
    return ans;
    
}
    
    