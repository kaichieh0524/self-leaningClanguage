// Top K Frequent Elements (medium)
// Runtime: 24 ms, faster than 59.09% of C online submissions for Top K Frequent Elements.
// Memory Usage: 8.5 MB, less than 43.48% of C online submissions for Top K Frequent Elements.


int count_diff_nums(int* nums,int numsSize){
    int comp = nums[0];
    int count = 1;
    for (int i = 0; i < numsSize; i++){
        if (nums[i]==comp){
            continue;
        }
        else {
            comp = nums[i];
            count += 1;
        }
    }
    return count;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0 || k==0){*returnSize=0; return NULL;}
    qsort(nums, numsSize, sizeof(int), cmpfunc);   
   

    int count_diff = count_diff_nums(nums,numsSize);
    int** buffer = malloc(sizeof(int*) * count_diff);
    int* ans = malloc(sizeof(int) * k);
    int cmp = nums[0];
    int count = 0;
    int flag = 0;
    *returnSize = k;
    
    for (int i = 0; i < count_diff; i++) {
        buffer[i] = malloc(sizeof(int) * 2);
    }


    
    for (int i = 0; i < numsSize; i++) {        
        if (cmp == nums[i]) {
            count += 1;
        }
        else {
            buffer[flag][0] = count;
            buffer[flag][1] = cmp;
            flag++;
            cmp = nums[i];
            count = 1;
            
        }
        if (i == numsSize - 1) {
            buffer[flag][0] = count;
            buffer[flag][1] = cmp;
        }
    }

    printf("----------------------------------------------\n");

    for (int i = 0; i < count_diff; i++) {
        
            printf("num : %d, count : %d\n", buffer[i][1], buffer[i][0]);
        
    }
    printf("\n----------------------------------------------\n");
    
    
    for (int j = 0; j < k; j++) {
        int max = 0;
        int index = 0;
        for (int i = 0; i < count_diff; i++) {
            if (buffer[i][0] > max) {
                max = buffer[i][0];
                index = i;                
            }

        }
        ans[j] = buffer[index][1];
        buffer[index][0] = 0;
    }

    printf("ans : ");

    for (int i = 0; i < k; i++) {
        printf(" %d ", ans[i]);
    }
      
    
    return ans;
}