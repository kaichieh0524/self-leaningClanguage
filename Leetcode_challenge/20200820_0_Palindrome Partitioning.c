// Palindrome Partitioning (medium)
// Runtime: 16 ms, faster than 66.67% of C online submissions for Palindrome Partitioning.
// Memory Usage: 10 MB, less than 13.33% of C online submissions for Palindrome Partitioning.



bool ispalind(char* s, int end){
    if (end < 0){ return 0;}
    int start = 0;
    while (start < end)
    {
        if (s[start] != s[end]){
            return 0;
    }
        start++;
        end--;
    }
    return 1;
}




void subroutine(char* s, char*** ans, int** returnColumnSizes, int* returnSize, char** temp, int step)
{
    
    if (*s == 0)
    {        
        ans[*returnSize] = malloc(sizeof(char*)*step);
        for (int i = 0; i < step; i++)
        {
            ans[*returnSize][i] = malloc(sizeof(char)*(strlen(temp[i])+1));
            strcpy(ans[*returnSize][i], temp[i]); 
        }
        returnColumnSizes[0][(*returnSize)++] = step;
        return;
    } 
    
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (ispalind(s, i))
        {
            strncpy(temp[step], s, i + 1);
            temp[step][i+1] = '\0';
            subroutine(s+i+1,ans,returnColumnSizes,returnSize,temp,step+1);
        }
    }    
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (s == NULL){return NULL;}
    int len = strlen(s)+1;
    
    returnColumnSizes[0] = malloc(sizeof(int)*500);
    char*** ans = malloc(sizeof(char**)*500);
    
    char** temp = malloc(sizeof(char*)*500);    
    for (int i = 0; i < 500; i++){
        temp[i] = malloc(sizeof(char)*len);
    }
    subroutine(s, ans,  returnColumnSizes,returnSize, temp, 0);
    
    return ans;
}








