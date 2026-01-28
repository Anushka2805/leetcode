class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // storing (num,freq)
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& it : freq) {
            // sorting by freq
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (k > 0) {
            int high = pq.top().second;
            pq.pop();
            ans.push_back(high);
            k--;
        }
        return ans;
    }
};