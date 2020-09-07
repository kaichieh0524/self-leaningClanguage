// Split a String in Balanced Strings (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Split a String in Balanced Strings.
// Memory Usage: 5.3 MB, less than 5.86% of C online submissions for Split a String in Balanced Strings.


int balancedStringSplit(char * s){
    int ans = 0;
    int cnt = 0;
    while (*s)
    {
        if (*s == 'R')
        {
            cnt++;
        } else
        {
            cnt--;
        }
        
        if (cnt == 0)
        {
            ans++;
        }
        s++;
    }
    
    return ans;
}