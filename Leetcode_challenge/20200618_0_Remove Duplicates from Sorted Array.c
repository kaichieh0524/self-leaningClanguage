//Remove Duplicates from Sorted Array (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 20 ms, faster than 69.33% of C online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 8.2 MB, less than 26.50% of C online submissions for Remove Duplicates from Sorted Array.


int removeDuplicates(int* nums, int numsSize){
    
    
    if (numsSize==0){
        return NULL;
    }
    if (numsSize==1){
        //printf("answer : %d", nums[0]);
        return 1;
    }
    
    
    int counter ;
    int flag = 0;
    
   for (counter=0; counter<numsSize;counter++){
       if (nums[counter]!= nums[flag]){
           flag++;
           nums[flag] = nums[counter];
       }
   }

    //printf("%d",flag);
    
    return flag+1;
}