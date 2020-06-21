// Single Number (easy)
// Runtime: 8 ms, faster than 95.39% of C online submissions for Single Number.
// Memory Usage: 6.4 MB, less than 88.06% of C online submissions for Single Number.

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0 ; i < numsSize ; i++){
        ans ^= nums[i];
    }
    printf("%d",ans);
    return ans;
}