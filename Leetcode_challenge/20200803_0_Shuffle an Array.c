// Shuffle an Array (medium)
// Runtime: 220 ms, faster than 72.09% of C online submissions for Shuffle an Array.
// Memory Usage: 35.4 MB, less than 100.00% of C online submissions for Shuffle an Array.

void swap (int* a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


typedef struct {
    int* nums;
    int* shufflenums;
    int len;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    srand(time(NULL));
    Solution* solution = malloc(sizeof(Solution));
    solution->len = numsSize;
    solution->nums = malloc(sizeof(int)*numsSize);
    solution->shufflenums = malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++){
        (solution->nums)[i] = nums[i];
        (solution->shufflenums)[i] = nums[i];
    }

    return solution;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj -> len;
    return obj->nums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    for (int i = 0; i < obj -> len; i++){
        int j = rand() % (obj -> len);
        swap(&(obj->shufflenums)[i],&(obj->shufflenums)[j]);
    }
    *retSize = obj -> len;
    return obj->shufflenums;
}

void solutionFree(Solution* obj) {
    free(obj);
    return;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/