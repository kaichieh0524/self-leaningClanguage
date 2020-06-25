// House Robber (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for House Robber.
// Memory Usage: 5.5 MB, less than 69.32% of C online submissions for House Robber.

int rob(int* nums, int numsSize){
   if (numsSize == 0){return 0;}
   if (numsSize == 1){return nums[0];}
   if (numsSize == 2){return fmax(nums[0],nums[1]);}
   int max_[numsSize];
    max_[0] = nums[0];
    max_[1] = fmax(nums[0],nums[1]);    
   for (int i = 2 ; i < numsSize ; i++)
   {
       max_[i] = fmax(max_[i-2]+nums[i],max_[i-1]);
   }
    return max_[numsSize-1];
}