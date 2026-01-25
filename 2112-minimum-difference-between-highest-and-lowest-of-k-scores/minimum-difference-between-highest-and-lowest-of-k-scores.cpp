class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int p = 0; p + k - 1 < n; p++) {
            int j = p + k - 1;
            int diff = nums[p + k - 1] - nums[p];
            ans = min(ans, diff);
        }
        return ans;
    }
};