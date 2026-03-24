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
        int x_par = find(x);
        int y_par = find(y);
        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        } else { // if both parents are =
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int components = n;
        for (auto& it : connections) {
            if (find(it[0]) != find(it[1])) {
                Union(it[0], it[1]);
                components--;
            }
        }
        return components - 1;
    }
};