class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        vector<pair<int, char>> seq;
        string ans = "";
        for (char ch : s) {
            freq[ch]++;
        }
        for (auto& it : freq) {
            seq.push_back({it.second, it.first}); // char,freq
        }
        sort(seq.rbegin(), seq.rend());
        for (auto &it : seq) {
            ans.append(it.first, it.second);
        }
        return ans;
    }
};