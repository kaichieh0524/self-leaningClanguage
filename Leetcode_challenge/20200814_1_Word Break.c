// Word Break (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Word Break.
// Memory Usage: 5.5 MB, less than 72.22% of C online submissions for Word Break.
// reference https://leetcode.com/problems/word-break/discuss/477488/c-0ms-o(m*n)


bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    if (wordDictSize == 0 ){return 0;}
    
    int len = strlen(s);
    bool* temp = calloc(len+1,sizeof(bool));
    int* wordlen = calloc(wordDictSize,sizeof(int));
    
    temp[0] = 1;
    for (int i = 0; i < wordDictSize; i++){
        wordlen[i] = strlen(wordDict[i]);
    }
    
    for (int i = 0; i < len; i++){
        if (temp[i]){
            for (int j = 0; j < wordDictSize; j++){
                int t = i + wordlen[j];
                if ( t < len + 1){
                    char t1 = s[t];
                    s[t] = NULL;
                    temp[t] = temp[t] || (strcmp(s + i, wordDict[j]) == 0);
                    s[t] = t1;
                }
            }
        }
    }
    return temp[len];
}

