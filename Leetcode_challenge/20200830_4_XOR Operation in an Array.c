// XOR Operation in an Array (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for XOR Operation in an Array.
// Memory Usage: 5.1 MB, less than 54.21% of C online submissions for XOR Operation in an Array.


int xorOperation(int n, int start){
    int ans = start;
    for (int i = 1; i < n; i++){
        ans ^= start + 2*i;
    }
    return ans;
}