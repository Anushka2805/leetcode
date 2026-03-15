class Solution {
public:
    // using bfs
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int initialClr = image[sr][sc];
        if (initialClr == color) {
            return image;
        }
        queue<pair<int, int>> q; // coordinates store
        q.push({sr, sc});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //assigning the main color
            image[x][y] = color;
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < m && j >= 0 && j < n &&
                    image[i][j] == initialClr) {
                    q.push({i, j});
                }
            }
        }
        return image;
    }
};