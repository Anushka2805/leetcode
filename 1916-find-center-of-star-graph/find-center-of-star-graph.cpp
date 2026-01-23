class Solution {
public:
//using hashmap
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for (auto& it : edges) {
            m[it[0]]++;
            m[it[1]]++;
        }
        int n = edges.size();
        for (auto& it : m) {
            if (it.second == n) {
                return it.first;
            }
        }
        return -1;
    }
};