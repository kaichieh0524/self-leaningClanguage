// Valid Anagram (easy)
// Runtime: 4 ms, faster than 74.78% of C online submissions for Valid Anagram.
// Memory Usage: 5.7 MB, less than 7.60% of C online submissions for Valid Anagram.
// key idea : use the table to store the character

bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {return 0;}
    int* count1= calloc(26 , sizeof(int));
    int* count2= calloc(26 , sizeof(int));
    int i = 0;
    while(s[i]!='\0')
    {
        count1[(s[i]%97)]+=1;
        count2[(t[i]%97)]+=1;
        i++;
    }
    i=0;
    while(s[i]!='\0')
    {
        if (count1[(s[i]%97)]!=count2[(s[i]%97)]){return 0;}
        i++;
    }
    return 1;
}