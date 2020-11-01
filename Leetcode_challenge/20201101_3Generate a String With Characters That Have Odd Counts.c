// Generate a String With Characters That Have Odd Counts (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Generate a String With Characters That Have Odd Counts.
// Memory Usage: 6.2 MB, less than 79.17% of C online submissions for Generate a String With Characters That Have Odd Counts.


char * generateTheString(int n){
    char* ans = malloc(sizeof(char)*501);
    
    if (n % 2 == 0){
        for (int i = 0; i < n - 1; i++){
            ans[i] = 'a';
        }
        ans[n-1] = 'b';
    }
    else{
        for (int i = 0; i < n; i++){
            ans[i] = 'a';
        }
    }
    ans[n] = '\0';
    return ans;
}