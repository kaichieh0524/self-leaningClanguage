// H-Index II (medium)
// Runtime: 8 ms, faster than 100.00% of C online submissions for H-Index II.
// Memory Usage: 9.1 MB, less than 45.71% of C online submissions for H-Index II.


int hIndex(int* citations, int citationsSize){
    int n = citationsSize;
    for (int i = 0; i < citationsSize; i++){
        if (citations[i] < n){n--;}
    }
    return n;
}