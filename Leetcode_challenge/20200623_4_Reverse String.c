// Reverse String (easy)
// Runtime: 52 ms, faster than 29.20% of C online submissions for Reverse String.
// Memory Usage: 12.2 MB, less than 7.42% of C online submissions for Reverse String.

void reverseString(char* s, int sSize){
    int end_index = sSize/2 ;
    for (int i =sSize-1 ; i >= end_index  ; i--)
    {
        char temp = s[(sSize-1)-i];
        s[(sSize-1)-i] = s[i];
        s[i] = temp ;
    }
}