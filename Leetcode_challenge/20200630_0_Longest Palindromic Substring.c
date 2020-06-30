//  Longest Palindromic Substring (medium)
// Runtime: 476 ms, faster than 7.66% of C online submissions for Longest Palindromic Substring.
// Memory Usage: 5.4 MB, less than 91.64% of C online submissions for Longest Palindromic Substring.
// the runtime is terrible.... it should be modified.
bool check(char* s, int i, int j)
{   
    int l,m;
    if ((j + i) % 2 != 0) {
        l = (j + i) / 2;
        m = l + 1;
    }
    else
    {
        l = (j + i) / 2;
        m = l;
    }
    while (i < j && l >= i && m <= j)
    {
        if (s[i] != s[j]) { return 0; }
        if (s[l] != s[m]) { return 0; }
        l--;
        m++;
        i++;
        j--;
    }
    return 1;
}

char * longestPalindrome(char * s){
    int i = 0;
    float len = strlen(s);
    int j = len-1;
    int max = 0;
    int flag = 0;
    for (i = 0; i <= j ; i++)
    {
        i = 0;
         while (i<=j)
        {   
            if (s[i] == s[j])
            {
                if (check(s, i, j) == 1 && i <= j)
                {
                    if (j - i + 1 > max)
                    {
                        max = j - i + 1;
                        flag = i;
                    }
                }
                i++;
            }
            
            else
            {
                i++;
            }
             
        }
        if (max >= j+ 1 ){break;}
        j = j - 1 ;
        i = 0;
    }
    // printf("the len : %d\n the flag : %d", max, flag);
    // printf("\n The ans string :");
    // for (int i = flag; i < flag + max; i++) {
    //     printf("%c", s[i]);
    // }
    char* ans = malloc(sizeof(char)*(max+1));
    for (int i = 0; i <  max; i++) {
        ans[i] = s[i+flag];
    }
    ans[max]='\0';
    return ans;
    
}