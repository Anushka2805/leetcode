class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        int freqMax = 0;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                m[nums[i]]++;
            }
        }
        for (auto& it : m) {
            if (it.second > freqMax) {
                freqMax = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};