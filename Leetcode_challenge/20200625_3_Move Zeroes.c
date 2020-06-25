// Move Zeroes (easy)
// Runtime: 12 ms, faster than 86.17% of C online submissions for Move Zeroes.
// Memory Usage: 7.3 MB, less than 83.60% of C online submissions for Move Zeroes.

void moveZeroes(int* nums, int numsSize){
    int count = 0;
    int flag = 0;
    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i]==0){count++;}
        else{nums[flag]=nums[i]; flag++;}
    }
    for ( int j = numsSize-count ; j < numsSize ; j++){
        nums[j]=0;
    }
}