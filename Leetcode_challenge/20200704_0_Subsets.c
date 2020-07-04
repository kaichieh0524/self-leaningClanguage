// Subsets (medium)
// Runtime: 4 ms, faster than 94.57% of C online submissions for Subsets.
// Memory Usage: 10.1 MB, less than 17.14% of C online submissions for Subsets.


int flag = 0;

void findsubset(int step,int* nums, int numsSize, int* temp, bool* used,int count,int** ans,int** returnColumnSizes) {
    if (step == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            printf("%d", temp[i]);
        }
        printf("\ncount : %d", count);
        printf("\n---------------------------------------\n");
        returnColumnSizes[0][flag] = count;
        if (count != 0) {
            ans[flag] = malloc(sizeof(int) * count);
            int index = 0;

            for (int i = 0; i < numsSize; i++) {
                if (temp[i] != NULL) {
                    ans[flag][index] = temp[i];
                    index++;
                }
            }
            while (index < count) {
                ans[flag][index] = 0;
                index++;
            }
        }
        else {
            ans[flag] = NULL;
        }
        flag++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            temp[step] = nums[step];
            findsubset(step + 1, nums, numsSize, temp, used,count+1,ans, returnColumnSizes);
            temp[step] = NULL;
        }
        if (i == 1) {
            
            findsubset(step + 1, nums, numsSize, temp, used,count,ans, returnColumnSizes);
        }
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    flag = 0;
    int* temp = calloc(numsSize, sizeof(int));
    bool* used = calloc(numsSize, sizeof(bool));
    int** ans = malloc(sizeof(int*) * ((int) pow(2, numsSize)));     
    *returnColumnSizes = malloc(sizeof(int*) * ((int)pow(2, numsSize)));
    findsubset(0, nums, numsSize, temp, used,0,ans, returnColumnSizes);
    *returnSize = (int) pow(2, numsSize);
     
    printf("the returncolumnsizes : ");
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", returnColumnSizes[0][i]);
    }
     printf("\n---------------------------------------\n");
    
    return ans;
}