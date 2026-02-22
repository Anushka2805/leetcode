class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int ans = 0;
        // we ll go till 32 as 10*3 = 2^10 approx
        // so cubing both sides  2^30 so 32 bits
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) > 0) {
                if (prev != -1) {
                    ans = max(ans, i - prev);
                }
                prev = i;
            }
        }
        return ans;
    }
};