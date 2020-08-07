// Wiggle Sort II (medium)
// Runtime: 52 ms, faster than 100.00% of C online submissions for Wiggle Sort II.
// Memory Usage: 12.8 MB, less than 100.00% of C online submissions for Wiggle Sort II. 
    
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void wiggleSort(int* nums, int numsSize){
    int* ans = malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++){
        ans[i] = nums[i];
    }
    qsort(ans , numsSize, sizeof(int), cmpfunc);
    int mid = (numsSize+1) / 2   ;
    int end = numsSize ;
    for (int i = 0; i < numsSize; i++){
        if (i%2 == 0){
            nums[i] = ans[--mid];
        }
        else{
            nums[i] = ans[--end];
        }
    }
}
