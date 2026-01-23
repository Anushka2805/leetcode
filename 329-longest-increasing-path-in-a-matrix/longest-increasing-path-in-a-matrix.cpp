class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int length = 1;
        int y[] = {-1, 0, 1, 0};
        int x[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nRow = i + x[k];
            int mCol = j + y[k];
            if (nRow >= 0 && mCol >= 0 && nRow < n && mCol < m &&
                matrix[nRow][mCol] > matrix[i][j]) {
                length = max(length, 1 + dfs(nRow, mCol, matrix, dp));
            }
        }
        return dp[i][j] = length;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};