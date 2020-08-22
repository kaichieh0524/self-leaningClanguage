// Is Subsequence (easy)
// Runtime: 4 ms, faster than 40.56% of C online submissions for Is Subsequence.
// Memory Usage: 5.2 MB, less than 59.44% of C online submissions for Is Subsequence.


bool isSubsequence(char * s, char * t){
    int index1 = 0;
    int index2 = 0;
    while(t[index2]!='\0'){
        if(s[index1] == t[index2]){
            index1++;
        }
        index2++;
    }
    if (s[index1] == '\0'){return 1;}
    return 0;
}