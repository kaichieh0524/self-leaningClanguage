// Permutations (medium)
// Runtime: 8 ms, faster than 94.39% of C online submissions for Permutations.
// Memory Usage: 6.8 MB, less than 81.94% of C online submissions for Permutations.


int flag = 0;

void f(int index, int* nums, int numsSize, int* temp, bool* used, int** ans);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    
    flag = 0;    
    bool* used = calloc(numsSize, sizeof(bool));    
    int* temp = malloc(sizeof(int) * numsSize);
    int total = 1;

    for (int i = 0; i < numsSize; i++) {
        total *= (i + 1);
    }
    printf("--------------------------------------\n");
    printf("The total number is : %d", total);
    printf("\n--------------------------------------\n");
    
    *returnSize = total;
    int** ans = malloc(sizeof(int*) * total);    
    *returnColumnSizes = malloc(sizeof(int) * total);

    for (int i = 0; i < total; i++) {
        ans[i] = malloc(sizeof(int)*numsSize);
        returnColumnSizes[0][i] = numsSize;
    }   

    f(0, nums, numsSize, temp, used,ans);
    
    for (int i = 0; i < total; i++) {
        printf("\n The %d-th ans is :", i+1);
        for (int j = 0; j < numsSize; j++) {
            printf("%d",ans[i][j]);
        }
    }
    printf("\n--------------------------------------\n");
    
    return ans;
}

void f(int index, int* nums, int numsSize, int* temp, bool* used, int** ans) {

    if (index == numsSize)
    {

        for (int i = 0; i < numsSize; i++) {
            //printf("%d", temp[i]);
            ans[flag][i] = temp[i];
        }
        //printf("\n");
        flag++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i])
        {
            used[i] = 1;
            temp[index] = nums[i];
            f(index + 1, nums, numsSize, temp, used,  ans);
            used[i] = 0;
        }


    }
}