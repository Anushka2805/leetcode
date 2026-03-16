class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        long long suffixSum = 0;
        long long prefixSum = 0;
        for (int num : nums) {
            suffixSum += num;
        }
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            suffixSum -= nums[i];
            if (prefixSum >= suffixSum) {
                count++;
            }
        }
        return count;
    }
};