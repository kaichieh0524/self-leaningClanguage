

int findNumbers(int* nums, int numsSize){
    int count = 0;
    for (int i = 0; i < numsSize; i++){
        if (((int)log10(nums[i])+1) % 2 == 0){            
            count++;
        }        
    }    
    return count;
}