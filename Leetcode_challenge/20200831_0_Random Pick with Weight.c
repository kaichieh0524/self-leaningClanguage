// Random Pick with Weight (medium)
// Runtime: 256 ms, faster than 47.54% of C online submissions for Random Pick with Weight.
// Memory Usage: 28.1 MB, less than 52.46% of C online submissions for Random Pick with Weight.



typedef struct {
    int* nums;
    int numsSize;
    int* count;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    Solution* solution = malloc(sizeof(Solution));
    solution -> nums = w;
    solution -> numsSize = wSize;
    solution -> count = malloc(sizeof(int)*wSize);
    int n = 0;
    for (int i = 0; i < wSize; i++){
        n += w[i];
        solution->count[i] = n;
    }
    return solution;
}

int solutionPickIndex(Solution* obj) {
    int index = rand()% ((obj->count)[(obj->numsSize)-1]);
    int n = 0;
    for (int i = 0; i < obj->numsSize; i++){
        if (index < obj->count[i]){
            n = i ;
            break;
        }
    }
    return n;
}

void solutionFree(Solution* obj) {
    free(obj->nums);
    free(obj->count);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/