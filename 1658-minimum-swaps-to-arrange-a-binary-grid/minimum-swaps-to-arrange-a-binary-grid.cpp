class Solution {
public:
    // can swap only adj rows
    // find trailing zeroes at end
    // need = n - rowNum - 1
    // swap = j - i
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> end0;
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            int count = 0;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            end0.push_back(count);
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;
            while (j < n && end0[j] < need ) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            swaps += j - i;
            while (j > i) {
                swap(end0[j], end0[j-1]);
                j--;
            }
        }
        return swaps;
    }
};