class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> newMat(m, vector<int>(n, 0));
        k = k % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // even row -> right shift
                if (i % 2 == 0) {
                    newMat[i][(j + k) % n] = mat[i][j];
                } else {
                    // odd row -> left shift
                    newMat[i][j] = mat[i][(j + k) % n];
                }
            }
        }
        if (newMat == mat) {
            return true;
        }
        return false;
    }
};