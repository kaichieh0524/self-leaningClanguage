// Self Dividing Numbers (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Self Dividing Numbers.
// Memory Usage: 6.1 MB, less than 11.25% of C online submissions for Self Dividing Numbers.


bool test(int n){
    float x = n;
    while(n != 0){
        int y = n % 10;

        if (y == 0 || x/y != (int) x / y){
            return 0;
        }
        n /= 10;
    }
    return 1;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int* ans = malloc(sizeof(int)* (right - left + 1));
    *returnSize = 0;
    for (int i = left; i <= right; i++){
        if (test(i)){
             ans[(*returnSize)++] = i;
        }
    }

    return ans;
}