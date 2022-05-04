int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

class Solution {
    public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        int color = 1;
        vector<vector<int>> used(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!used[i][j] and grid[i][j] == 1) {
                    color ++;
                    queue<pair<int, int>> qu; 
                    qu.push({i, j});
                    used[i][j] = true;
                    grid[i][j] = color;

                    while (!qu.empty()) {
                        auto [ux, uy] = qu.front(); 
                        qu.pop();

                        for (int d = 0; d < 4; d++) {
                            int vx = ux + dr[d]; 
                            int vy = uy + dc[d];

                            if (vx < 0 or vy < 0 or vx >= n or vy >= m)
                                continue; 
                            if (grid[vx][vy] == 0) 
                                continue;
                            if (used[vx][vy]) 
                                continue;

                            grid[vx][vy] = color;
                            qu.push({vx, vy});
                            used[vx][vy] = true;
                        }
                    }
                }
            }
        }

        queue<pair<int, int>> qu;
        used = vector<vector<int>>(n, vector<int>(m, false));
        for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    qu.push({i, j});
                    used[i][j] = true;
                }
                cout << grid[i][j] << ' ';
            }  cout << '\n';
        }
        cout << "\n\n";

        while (!qu.empty()) {
            auto [ux, uy] = qu.front(); qu.pop();
            for (int d = 0; d < 4; d++) {
                int vx = ux + dr[d]; 
                int vy = uy + dc[d];  

                if (vx < 0 or vy < 0 or vx >= n or vy >= m)
                    continue; 
                if (used[vx][vy]) 
                    continue;

                used[vx][vy] = used[ux][uy] + 1;
                qu.push({vx, vy});
            }
        }
        int ans = INT_MAX;
        for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 3) {
                    ans = min(ans, used[i][j]);
                }
                  cout << used[i][j] << ' ';
            }   cout << '\n';
        }
        if (ans == 0) return 0;
        return ans - 2;
    }
};
/*
0 1
1 0

*/