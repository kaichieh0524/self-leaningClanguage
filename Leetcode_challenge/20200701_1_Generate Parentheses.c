// Generate Parentheses (medium)
// Runtime: 4 ms, faster than 78.18% of C online submissions for Generate Parentheses.
// Memory Usage: 11.5 MB, less than 70.51% of C online submissions for Generate Parentheses.
    
int total = 0;
int flag = 0;
void f(int n,int index, char* temp, int left, int right, char** ans);


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    flag = 0;
    total = 0;
    char** ans = malloc(sizeof(char*)*1500);
    char* temp = malloc(sizeof(char) * 2 * n+1);
    
    temp[0] = '(';
    f(n,1, temp, 1, 0, ans);
    
//     printf("\n------------------------------------\n");
    
      *returnSize = total;
    
//     printf("\nthe number of different ans is : %d\n", *returnSize);
//     printf("\n------------------------------------\n");
    
//     for (int i = 0; i < total; i++)
//     {
//         printf("\nThe %d-th ans is : %s\n", i + 1, ans[i]);
//     }
    return ans;
}

void f(int n,int index, char* temp, int left, int right, char** ans) {

    if (left == n && right == n) {
        temp[2*n] = '\0';
        //printf("%s\n", temp);
        total++;
        char* buffet = malloc(sizeof(char) * 2 * n + 1);
        strcpy(buffet, temp);
        ans[flag] = buffet;
        flag++;
        return;
    }

    if (left < n) {
        temp[index] = '(';
        f(n,index + 1, temp, left + 1, right,ans);

    }
    if (left > right) {
        temp[index] = ')';
        f(n,index + 1, temp, left, right + 1,ans);
    }


}