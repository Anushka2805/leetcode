class Solution {
public:
    // 90 degree rorate = transpose the matrix -> reverse the rows
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool match(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int rotations = 0;rotations<4;rotations++){
            if(match(mat,target)){
                return true;
            }
            rotate90(mat);
        }
        return false;
    }
};