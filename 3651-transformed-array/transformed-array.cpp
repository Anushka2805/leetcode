class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
         vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int newPos = (i + nums[i]) % n;
            if (newPos < 0) {
                newPos += n;
            }
            ans[i] = nums[newPos];
        }
        return ans;
    }
};