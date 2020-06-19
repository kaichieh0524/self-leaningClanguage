//Maximum Subarray (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 4 ms, faster than 97.52% of C online submissions for Maximum Subarray.
// Memory Usage: 6.2 MB, less than 14.37% of C online submissions for Maximum Subarray.

int maxSubArray(int* nums, int numsSize){
    int temp=nums[0], max=nums[0];
    
    for (int i = 1; i < numsSize; i++) {
		temp += nums[i];
		if (temp < nums[i]) {
			temp = nums[i];
		}
		if (temp > max) {
			max = temp;
		}
	}
	printf("The ans is : %d", max);
    return max;

}