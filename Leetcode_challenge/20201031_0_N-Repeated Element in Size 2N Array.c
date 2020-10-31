// N-Repeated Element in Size 2N Array
// Runtime: 52 ms, faster than 13.21% of C online submissions for N-Repeated Element in Size 2N Array.
// Memory Usage: 12.3 MB, less than 21.70% of C online submissions for N-Repeated Element in Size 2N Array.

int repeatedNTimes(int* A, int ASize){
    int* temp = calloc(10001, sizeof(int));
    for (int i = 0; i < ASize; i++){
        temp[A[i]]++;
    }
   
    for (int i = 0; i < 10001; i++){
        if (temp[i] == ASize/2){
            return i;
        }
    }
    return 0;
}