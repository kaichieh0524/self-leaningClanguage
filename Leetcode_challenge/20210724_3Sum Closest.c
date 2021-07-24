// 3Sum Closest (medium)
// Runtime: 8 ms, faster than 66.48% of C online submissions for 3Sum Closest.
// Memory Usage: 5.9 MB, less than 45.45% of C online submissions for 3Sum Closest.

#define MAX INT_MAX

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    int ans = MAX;
    int right, left;
    int sum, diff;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize; i++){
        left = i + 1;
        right = numsSize - 1;
        while(left < right){
            sum = nums[i] + nums[right] + nums[left];
            diff = target - sum;
            ans = abs(diff) < abs(ans) ? diff : ans;
            if(diff == 0){
                break;
            }else if (diff < 0){
                right--;
            }else{
                left++;
            }
        }
    }
    return target - ans;
}