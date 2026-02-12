class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxNum = nums[0];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                idx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if(i == idx){
                continue;
            }
            if (maxNum < 2 * nums[i]) {
                return -1;
            }
        }
        return idx;
    }
};