class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n));
        int MOD = 12345;
        //calc suffix from end
        long long suffix = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }
        //calc prefix from start and multiplying it with suffix
        long long prefix = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = (prefix * p[i][j]) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }
        return p;
    }
};