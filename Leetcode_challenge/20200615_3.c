//Roman to Integer (easy)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
/*
Runtime: 8 ms, faster than 45.48% of C online submissions for Roman to Integer.
Memory Usage: 5.5 MB, less than 62.30% of C online submissions for Roman to Integer.
*/
int romanToInt(char * s){
    
       
    char* y[3] = {s, s+1};
    int ans = 0;
    
    while (*y[0] != '\0')
    {   
        if (*y[0] == 'I' && *y[1] == 'V') {
            ans  += 4;
            y[0] += 2;
            y[1] += 2;
        }
        else if (*y[0] == 'I' && *y[1] == 'X') {
            ans  += 9;
            y[0] += 2;
            y[1] += 2;
        }
        else if (*y[0] == 'X' && *y[1] == 'L') {
            ans  += 40;
            y[0] += 2;
            y[1] += 2;
        }
        else if (*y[0] == 'X' && *y[1] == 'C') {
            ans += 90;
            y[0] += 2;
            y[1] += 2;
        }
        else if (*y[0] == 'C' && *y[1] == 'D') {
            ans += 400;
            y[0] += 2;
            y[1] += 2;
        }
        else if (*y[0] == 'C' && *y[1] == 'M') {
            ans += 900;
            y[0] += 2;
            y[1] += 2;
        }
        else {
            if (*y[0] == 'I') {
                ans += 1;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'V') {
                ans += 5;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'X') {
                ans += 10;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'L') {
                ans += 50;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'C') {
                ans += 100;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'D') {
                ans += 500;
                y[0]++;
                y[1]++;
            }
            if (*y[0] == 'M') {
                ans += 1000;
                y[0]++;
                y[1]++;
            }
        }
    }

    

    printf("answer : %d", ans);
    return ans;
}