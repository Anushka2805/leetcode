class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for (char c : s) {
            m[c]++;
        }
        for (auto& it : m) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            ans.append(freq, ch);
            pq.pop();
        }
        return ans;
    }
};