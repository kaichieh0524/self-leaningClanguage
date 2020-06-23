// Reverse Bits (easy)
// Runtime: 4 ms, faster than 24.58% of C online submissions for Reverse Bits.
// Memory Usage: 5.2 MB, less than 15.75% of C online submissions for Reverse Bits.
// it should be modified
uint32_t reverseBits(uint32_t n) {
    uint32_t a = 1;
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & a) { ans += pow(2,31-i); }
        a *= 2;
    }
    return ans;
}