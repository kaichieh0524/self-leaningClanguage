// Jump Game (mdeium)
// Runtime: 8 ms, faster than 92.37% of C online submissions for Jump Game.
// Memory Usage: 6.5 MB, less than 100.00% of C online submissions for Jump Game.


bool canJump(int* nums, int numsSize){
    if (numsSize == 1){return 1;}
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 0){
            int flag = 0;
            for (int j = 0; j < i; j++){
                if ( j + nums[j] > i || j + nums[j] == numsSize - 1){flag = 1; break;}
            }
            if (flag == 0){return 0;}
        }       
    }    
    return 1;
}