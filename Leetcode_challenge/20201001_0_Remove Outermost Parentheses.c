// Remove Outermost Parentheses (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove Outermost Parentheses.
// Memory Usage: 6.5 MB, less than 6.93% of C online submissions for Remove Outermost Parentheses.


void findecomp(char* s, int left, int right) {
    if (*s == '\0') { return; }

    while (*s != '\0') {

        if (*s == '(') {            
            if (!left && !right) {
                *s = 'a';
            }
            left++;
        }
        else {
            right++;
        }
        if (left && right && left == right) {
            *s = 'a';
            findecomp(s + 1, 0, 0);
            return;
        }
        s = s + 1;

        
    }

}

char * removeOuterParentheses(char * S){
    int left = 0, right = 0, index = 0, n = 0;
    findecomp(S, 0, 0);
    char* ans = malloc(sizeof(char) * 10000);
     while (S[index] != '\0') {
        if (S[index] != 'a') {
            ans[n++] = S[index];
        }
        index++;
    }
    ans[n] = '\0';
    
    return ans;
}