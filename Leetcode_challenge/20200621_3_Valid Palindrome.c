//Valid Palindrome (easy)
#include<stdio.h> 
#include<string.h> 

// Runtime: 4 ms, faster than 58.81% of C online submissions for Valid Palindrome.
// Memory Usage: 6 MB, less than 36.46% of C online submissions for Valid Palindrome.

bool isPalindrome(char * s){
    
    int len = strlen(s);
    
    if (len == 0) { return 1; }
    int i = 0;
    int j = len - 1;
    while (j != i && j > i) {
        while (isspace(s[i])  || ispunct(s[i])  ) {
            i++;
            if (i > len - 1) { return 1; }
        }
        while (isspace(s[j]) || ispunct(s[j])  ) {
            j--;
        }

        if (abs(toupper(s[i]) - toupper(s[j]) != 0 )) { return 0; }
        
        i++;
        j--;
    }
    return 1;
}