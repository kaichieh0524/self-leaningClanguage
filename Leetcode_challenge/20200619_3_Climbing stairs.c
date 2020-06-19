// Climbing stairs (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 0 ms, faster than 100.00% of C online submissions for Climbing Stairs.
// Memory Usage: 5.1 MB, less than 58.97% of C online submissions for Climbing Stairs.

int climbStairs(int n){
    
    if (n==1){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else{
        int preivous_1 = 2;
        int preivous_2 = 1;
        int current ;
        for (int i = 0 ; i < n-2 ; i++){
            current = preivous_1 + preivous_2;
            preivous_2 = preivous_1;
            preivous_1 = current;
        }
        printf("the ans is : %d", current);
        return current;
    }
    
    
}