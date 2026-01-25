class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int i = 0;
        int j = k - 1;
        while (j < n) {
            int diff = nums[j] - nums[i];
            ans = min(ans, diff);
            i++;
            j++;
        }
        return ans;
    }
};