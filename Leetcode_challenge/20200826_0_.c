// Single Number II (medium)
// Runtime: 4 ms, faster than 100.00% of C online submissions for Single Number II.
// Memory Usage: 6.7 MB, less than 7.52% of C online submissions for Single Number II.


int compare (void *a,  void *b) {
    if (*(int*)a>*(int*)b){return 1;}
    if (*(int*)a<*(int*)b){return -1;}
    return 0;
}

int singleNumber(int* nums, int numsSize){
    if (numsSize == 1){return nums[0];}
    qsort(nums,numsSize,sizeof(int),compare);
    int count;
    for (int i = 0; i < numsSize; i++){
        if (i == 0){
            if (nums[i]!=nums[i+1]){return nums[i];}
        }
        else if ( i == numsSize - 1){
            if (nums[i] != nums[i-1]){return nums[i];}
        }
        else{
            if (nums[i] != nums[i+1] && nums[i] != nums[i-1]){return nums[i];}
        }
    }
    return 0;
}