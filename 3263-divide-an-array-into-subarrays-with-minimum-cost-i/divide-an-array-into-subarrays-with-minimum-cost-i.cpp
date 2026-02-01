class Solution {
public:
//tc = n
    int minimumCost(vector<int>& nums) {
        int smallest = INT_MAX;
        int smaller = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                smaller = smallest;
                smallest = nums[i];
            } else if (nums[i] < smaller) {
                smaller = nums[i];
            }
        }
        return nums[0] + smaller + smallest;
    }
};