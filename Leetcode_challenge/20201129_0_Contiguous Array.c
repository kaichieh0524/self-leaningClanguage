// Contiguous Array (medium)
// Runtime: 92 ms, faster than 77.78% of C online submissions for Contiguous Array.
// Memory Usage: 16.2 MB, less than 50.00% of C online submissions for Contiguous Array.



int findMaxLength(int* nums, int numsSize){
    int max = 0;
    int count = 0;
    int* countarray = calloc(2*numsSize+1, sizeof(int));
    for (int i = 0; i < 2*numsSize + 1; i++){
        countarray[i] = -1;
    }
    for (int i = 0; i < numsSize; i++){
        count += nums[i] ? 1 : -1;
        if (count == 0){
            max = i+1;
        }
        else if (countarray[count + numsSize] != -1){
            max = fmax(max, i - countarray[count + numsSize]);
        }
        else {
            countarray[count + numsSize] = i;
        }        
    }    
    return max;
}


