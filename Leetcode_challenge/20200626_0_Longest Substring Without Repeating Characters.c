// Longest Substring Without Repeating Characters (medium)
// Runtime: 388 ms, faster than 5.30% of C online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 294.1 MB, less than 5.07% of C online submissions for Longest Substring Without Repeating Characters.
// it needs to be modified
// Approach 1
int subroutine(char* s)
{
    int n = strlen(s);
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    char* ans = malloc(sizeof(char) * n);
    ans[0] = s[0];
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= flag; j++)
        {
            if (ans[j] == s[i])
            {
                return i;
            }
        }
        ans[i] = s[i];
        flag++;
    }
    return n;
}

int lengthOfLongestSubstring(char * s){
    int max = 0;

    while (s[0] != '\0')
    {
        int len = subroutine(s);
        max = fmax(len, max);
        s += 1;
    }
    printf("%d", max);
    return max;
}