// Next Permutation (medium)
// Runtime: 8 ms, faster than 57.85% of C online submissions for Next Permutation.
// Memory Usage: 6.3 MB, less than 42.98% of C online submissions for Next Permutation.


void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;

}

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void nextPermutation(int* nums, int numsSize){
    int flag = nums[numsSize - 1];
    int index1=0;
    int index2=numsSize-1;
    bool temp = 0;
    for (int i = numsSize - 2; i >=0; i--){
        if (nums[i] < flag){
            index1 = i;
            temp = 1;
            break;
            
        }
        flag = nums[i];
        
    }
    if (!index1 && numsSize!=2 && temp!=1){
        qsort(nums, numsSize , sizeof(int), cmp);
        return;
    }

    printf("%d",index1);
    for (int i = numsSize - 1; i > index1; i--){
        if(nums[i] > nums[index1]){
            index2 = i;
            break;
        }
    }
    printf("\n%d",index2);
    swap(&nums[index1],&nums[index2]);
    qsort(nums+index1+1, numsSize - index1-1, sizeof(int), cmp);
}