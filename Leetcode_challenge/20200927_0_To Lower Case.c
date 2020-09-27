// Runtime: 0 ms, faster than 100.00% of C online submissions for To Lower Case.
// Memory Usage: 5.6 MB, less than 5.22% of C online submissions for To Lower Case.

void helper(char* str){
    if(*str=='\0'){
        return;
    }
    if(*str >=65 && *str <= 90){
        *str = (char) *str+32;
    }
    helper(str+1);
}


char * toLowerCase(char * str){
    helper(str);
    return str;
}