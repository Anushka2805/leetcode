class Solution {
public:
    // inc->dec->inc
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        // inc
        while (i + 1 < n && nums[i + 1] > nums[i]) {
            i++;
        }
        if (i == 0 || i == n - 1) {
            return false;
        }
        // dec
        while (i + 1 < n && nums[i + 1] < nums[i]) {
            i++;
        }
        if (i == 0 || i == n - 1) {
            return false;
        }
        //inc
        while (i + 1 < n && nums[i + 1] > nums[i]) {
            i++;
        }
        if(i == n-1){
            return true;
        }
        return false;
    }
};