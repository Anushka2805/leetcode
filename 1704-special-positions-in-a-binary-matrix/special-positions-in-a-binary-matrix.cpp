class Solution {
public:
    // we will traverse and track 1s in that row or col
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row1(m, 0);
        vector<int> col1(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    row1[i]++;
                    col1[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && row1[i] == 1 && col1[j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};