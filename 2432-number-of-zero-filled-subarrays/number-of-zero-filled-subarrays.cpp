class Solution {
public:
//0,0,0,2,0,0
//subarr = 1->2->3->0->1->2
//ans = 1+2+3+1+2
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long subArr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                subArr += 1;
                ans += subArr;
            }else{
                subArr = 0;
            }
        }
        return ans;
    }
};