//count and say (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 4 ms, faster than 43.41% of C online submissions for Count and Say.
// Memory Usage: 7.1 MB, less than 17.50% of C online submissions for Count and Say.
    
char* f1(char* s) {
    int size = sizeof(char) * 10000;
    char* temp = malloc(size);
    int flag = 0;    
    int n =0;

    while (s[flag] != '\0') {
        int j;
        int counter = 1;
        for (j = flag+1; j < strlen(s); j++) {
            if (s[flag] == s[j]) {
                counter++;
            }
            else
            {
                break;
            }
        }        
        n+=sprintf(temp+n,  "%d", counter);
        n+=sprintf(temp+n,  "%c", s[flag]);
        flag = j;
    }

    return temp;
}

char * countAndSay(int n){
    
    char* s = "1";
    for (int i = 0; i < n-1; i++) {
        s = f1(s);
    }
    
    return s;
}