// Fizz Buzz (easy)
// Runtime: 16 ms, faster than 8.14% of C online submissions for Fizz Buzz.
// Memory Usage: 8.5 MB, less than 5.08% of C online submissions for Fizz Buzz.
// key idea : use the function sprintf or sprintf_s

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** ans = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = malloc(sizeof(char) * 100);
        if ((i+1) % 15 == 0) {
            ans[i]="FizzBuzz";
        }
        else if ((i + 1) % 3 == 0) {
            ans[i]="Fizz";
        }
        else if ((i + 1) % 5 == 0) {
            ans[i]="Buzz";
        }
        else {
            sprintf(ans[i], "%d", (i + 1));
        }
        printf("%s\n", ans[i]);
    }
    return ans;
}