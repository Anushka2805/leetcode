class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int xPar = find(x);
        int yPar = find(y);
        if (rank[xPar] > rank[yPar]) {
            parent[yPar] = xPar;
        } else if (rank[xPar] < rank[yPar]) {
            parent[xPar] = yPar;
        } else {
            parent[xPar] = yPar;
            rank[yPar]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        // mking components
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            Union(u, v);
        }
        // making map to store parent(comp) -> size of comp
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int par = find(i);
            m[par]++;
        }
        long long ans = 0;
        long long remNodes = n;
        for (auto& it : m) {
            long long size = it.second;
            ans += (size) * (remNodes - size);
            remNodes -= size;
        }
        return ans;
    }
};