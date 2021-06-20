// Partitioning Into Minimum Number Of Deci-Binary Numbers (medium)
// Runtime: 8 ms, faster than 86.97% of C online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
// Memory Usage: 8.2 MB, less than 27.31% of C online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.

int minPartitions(char * n){
    int max = 0;
    int length = strlen(n);
    for(int i = 0; i < length; i++){
        max = max < n[i] - '0' ? n[i] - '0' : max;
    }
    return max;
}