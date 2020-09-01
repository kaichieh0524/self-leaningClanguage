// Palindromic Substrings (medium)
// Runtime: 192 ms, faster than 16.98% of C online submissions for Palindromic Substrings.
// Memory Usage: 5.4 MB, less than 41.51% of C online submissions for Palindromic Substrings.


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

void subroutine(char* s,  int* count)
{
    
    if (*s == 0)
    {                
        return;
    }    
    int len = strlen(s);
    
    for (int i = 0; i < len; i ++){
        if (ispalind(s,i)){
            *count+=1;
        }
    }
    subroutine(s+1,count);
}

int countSubstrings(char * s){
     if (s == NULL){return 0;}  
    int* count = calloc(1,sizeof(int));   
    subroutine(s, count);    
    return *count;
}