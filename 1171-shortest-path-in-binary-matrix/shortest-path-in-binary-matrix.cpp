class Solution {
public:
    // using dijkstra algo
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        // can traverse in all directions
        int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return dist;
            }
            for (int k = 0; k < 8; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] &&
                    grid[i][j] == 0) {
                    q.push({{i, j}, dist + 1});
                    vis[i][j] = 1;
                }
            }
        }
        return -1;
    }
};