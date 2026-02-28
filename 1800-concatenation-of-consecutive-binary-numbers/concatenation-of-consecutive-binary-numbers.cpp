class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long ans = 0;
        for(int i = 1;i<=n;i++){
            int dig = log2(i)+1;
            ans = ((ans<<dig)%mod + i)%mod;
        }
        return ans;
    }
};