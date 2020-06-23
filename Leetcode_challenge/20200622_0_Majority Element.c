// Majority Element (easy)

// Runtime: 16 ms, faster than 94.74% of C online submissions for Majority Element.
// Memory Usage: 7.5 MB, less than 59.21% of C online submissions for Majority Element.

int majorityElement(int* nums, int numsSize){   
    int i,IndexOfMajElem = 0, ctr = 1;
    for(i = 1; i < numsSize; i++) 
	{
        if(nums[IndexOfMajElem] == nums[i])
            ctr++;
        else
            ctr--;
         
        if(ctr == 0) {
            IndexOfMajElem = i;
            ctr = 1;
        }
    }
	
    return nums[IndexOfMajElem];
}
