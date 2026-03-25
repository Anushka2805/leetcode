class Solution {
public:
    // two ptr approach
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (i<n && j < n) {
            if (i == j || nums[j] - nums[i] < k) {
                j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            } else {
                ans++;
                i++;
                while (i < n && nums[i] == nums[i - 1]) {
                    i++;
                }
            }
            if (i == j) {
                j++;
            }
        }
        return ans;
    }
};