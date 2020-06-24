// First Unique Character in a String (easy)
// Runtime: 8 ms, faster than 89.05% of C online submissions for First Unique Character in a String.
// Memory Usage: 6.8 MB, less than 12.99% of C online submissions for First Unique Character in a String.
// just use the similar idea of hash table


int firstUniqChar(char * s){
    int* count= calloc(27 , sizeof(int));
    int i = 0;
    while(s[i]!='\0')
    {
        count[(s[i]%96)]+=1;
        i++;
    }
    i=0;
    while(s[i]!='\0')
    {
        if (count[(s[i]%96)]==1){return i;}
        i++;
    }
    return -1;
}