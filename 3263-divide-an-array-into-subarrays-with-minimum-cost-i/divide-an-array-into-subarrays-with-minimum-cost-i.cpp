class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> newNum = nums;
        sort(newNum.begin() + 1, newNum.end());
        int sum = newNum[0] + newNum[1] + newNum[2];
        return sum;
    }
};