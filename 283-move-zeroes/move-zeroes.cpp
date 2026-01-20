class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        if (n == 1) {
            return;
        }
        int i = 0;
        int j = 1;
        while (i < n && j < n) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j = i + 1;
            } else if (nums[i] == 0 && nums[j] == 0) {
                j++;
            } else {
                i++;
                j = i + 1;
            }
        }
    }
};