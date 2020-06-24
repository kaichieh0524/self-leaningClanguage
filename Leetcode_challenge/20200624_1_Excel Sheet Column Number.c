//  Excel Sheet Column Number (easy)
// Runtime: 4 ms, faster than 100% of C online submissions for Excel Sheet Column Number.
// Memory Usage: 5.1 MB, less than 96.1% of C online submissions for Excel Sheet Column Number.


int titleToNumber(char * s){
    if (s==NULL){return 0;}
    int i = 0;
    int ans = 0;
    printf("%d",*s);
    while(s[i]!='\0')
    {
        ans = ans*26 + (s[i]%64);
        i++;
    }
    return ans;
}