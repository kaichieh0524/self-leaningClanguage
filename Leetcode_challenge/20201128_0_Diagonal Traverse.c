// Diagonal Traverse (medium)
// Runtime: 108 ms, faster than 7.69% of C online submissions for Diagonal Traverse.
// Memory Usage: 41.6 MB, less than 38.46% of C online submissions for Diagonal Traverse.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int insert(int* ans, int* res, int indexans, int lenres){
    for (int i = 0; i < lenres ; i++){
        ans[i + indexans] = res[i];
    }
    return indexans+lenres;
}

void reverse(int* nums, int len){
    for (int i = 0; i < len/2; i++){
        swap(&nums[i],&nums[len-i-1]);
    }
}

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){       
    *returnSize = 0;
    if (matrixSize == 0){return NULL;}
    int* ans = malloc(sizeof(int)*matrixSize*matrixColSize[0]); 
    int* res;
    int reslen = 0;
    int indexans = 0;
    int evenorodd = 0;
    int** used = malloc(sizeof(int*)*matrixSize);
    for (int i = 0; i < matrixSize; i++){
        used[i] = calloc(matrixColSize[0],sizeof(int));
    }
    
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixColSize[0]; j++){            
            if (used[i][j]){
                continue;
            }
            int k1 = i;
            int k2 = j;
            reslen = 0;
            res = calloc(100, sizeof(int));
            while(k1 >= 0 && k1 < matrixSize && k2 >= 0 && k2 < matrixColSize[0]){            
                res[reslen++] = matrix[k1][k2];
                used[k1][k2] = 1;                
                k1++;
                k2--;
            }

            if ( evenorodd % 2 == 0){
                reverse(res,reslen);
            }            
            insert(ans, res, indexans, reslen);
            evenorodd++;
            indexans += reslen;           
        }
    }    
    *returnSize = indexans;
    return ans;
}