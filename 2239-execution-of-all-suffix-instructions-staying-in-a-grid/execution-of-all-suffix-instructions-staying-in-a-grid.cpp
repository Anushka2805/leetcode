class Solution {
public:
    vector<int> executeInstructions(int y, vector<int>& startPos, string s) {
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int r = startPos[0];
            int c = startPos[1];
            int possibleMoves = 0;
            for (int j = i; j < n; j++) {
                char move = s[j];
                int nr = r;
                int nc = c;
                if (move == 'L') {
                    nc--;
                } else if (move == 'R') {
                    nc++;
                } else if (move == 'U') {
                    nr--;
                } else if (move == 'D') {
                    nr++;
                }
                if (nr < 0 || nr >= y || nc < 0 || nc >= y) {
                    break;
                }
                r = nr;
                c = nc;
                possibleMoves++;
            }
            ans.push_back(possibleMoves);
        }
        return ans;
    }
};