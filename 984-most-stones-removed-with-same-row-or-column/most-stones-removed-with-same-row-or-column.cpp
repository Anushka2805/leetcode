class Solution {
public:
    void dfs(vector<vector<int>>& stones, int i, vector<bool>& vis) {
        vis[i] = true;
        for (int k = 0; k < stones.size(); k++) {
            if (!vis[k] && (stones[i][0] == stones[k][0] ||
                            stones[i][1] == stones[k][1])) {
                dfs(stones, k, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(stones, i, vis);
            }
        }
        return n - count;
    }
};