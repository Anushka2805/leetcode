class Solution {
public:
    // using two ptr
    // side by side 0 ki freq count krenge <= k tk
    // if it becomes more than k then l++ and also store the length
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        int l = 0;
        int count0 = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                count0++;
            }
            while (count0 > k) {
                if (nums[l] == 0) {
                    count0--;
                }
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};