class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int eR = x + k - 1;
        int eC = y + k - 1;
        for (int i = x; i <= eR; i++) {
            for (int j = y; j <= eC; j++) {
                swap(grid[i][j], grid[eR][j]);
            }
            eR--;
        }
        return grid;
    }
};