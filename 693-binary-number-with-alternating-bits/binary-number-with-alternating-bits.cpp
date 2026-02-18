class Solution {
public:
// n = 1010
// n>>1 = 0101
// XOR result= 1111
// if original num is alternating then ans will have 1sss 
// ans = 1111 (binary)
// ans+1 = 10000
// AND = 00000 → 0

    bool hasAlternatingBits(int n) {
        unsigned int ans = n ^ (n >> 1);
        return (ans & (ans + 1)) == 0;
    }
};