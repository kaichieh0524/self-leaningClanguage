// Jewels and Stones (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Jewels and Stones.
// Memory Usage: 5.3 MB, less than 12.28% of C online submissions for Jewels and Stones.


int lowercase(char c){
    if  (c >= 97 && c <= 122){return 1;}
    return 0;
}



int numJewelsInStones(char * J, char * S){
    bool* hash = calloc(52,sizeof(bool));   
    int index = 0;
    int ans = 0;
    while(J[index]!='\0'){
        if (lowercase(J[index])){
            hash[J[index]-'a'] +=1;
        }
        else{
            hash[J[index]-'A' + 26] +=1;
        }
        index++;
    }
    index = 0;
    while(S[index]!='\0'){
        if (lowercase(S[index])){
            if (hash[S[index]-'a']){
                ans+=1;
            }
        }
        else{
           if(hash[S[index]-'A' + 26]){
             ans+=1;
           }
        }
        index++;
    }

    return ans;
}