// Number of 1 Bits (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Number of 1 Bits.
// Memory Usage: 5.1 MB, less than 59.44% of C online submissions for Number of 1 Bits.
// key idea : treat uint32_t as unsigned int nothing

int hammingWeight(uint32_t n) {
    int ans = 0;
    uint32_t mask = 1;
    for (int i = 0 ; i < 32 ; i++){
         printf("%d\n", mask & n);
        if ((mask&n) !=0)
        {
            ans+=1;
        }
        mask*=2;
    }
    return ans;
}