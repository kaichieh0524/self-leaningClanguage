// Queries on a Permutation With Key (medium)
// Runtime: 8 ms, faster than 92.86% of C online submissions for Queries on a Permutation With Key.
// Memory Usage: 6.4 MB, less than 28.57% of C online submissions for Queries on a Permutation With Key.



void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;

}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
    *returnSize = queriesSize;
    int* ans = malloc(sizeof(int)*queriesSize);
    int* permutation = malloc(sizeof(int)*m);

    for (int i = 0; i < m; i++){
        permutation[i] = i+1;
    }
    
    
    
    for (int i = 0; i < queriesSize; i++){
        for (int j = 0; j < m; j++){
            if (permutation[j] == queries[i]){
                ans[i] = j;
                for (int k = j; k > 0; k--){
                    swap(&permutation[k],&permutation[k-1]);
                }
                break;
            }
        }
    }
    return ans;
}