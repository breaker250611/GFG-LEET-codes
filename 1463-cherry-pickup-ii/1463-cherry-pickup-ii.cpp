#define vi vector<int> 
#define vvi vector<vi>

int dir[] = {-1, 0, 1};

class Solution {
public:
    vvi grid;
    vector<vvi> dp;
    int row, col;
    
    int fun(int r, int c1, int c2) {
        if (r == row) {
            return 0;
        }
        
        if (c1 < 0 or col <= c1 or c2 < 0 or col <= c2) {
            return -9999;
        }
        
        int &ans = dp[r][c1][c2]; 
        if (ans == -1) {
            ans = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int temp_i = dir[i] + c1; 
                    int temp_j = dir[j] + c2;
                    
                    if (c1 != c2) {
                        ans = max(ans, 
                                  fun(r + 1, temp_i, temp_j) + grid[r][c1] + grid[r][c2]);
                    } else {
                        ans = max(ans, 
                                  fun(r + 1, temp_i, temp_j) + grid[r][c1]);
                    }
                }
            }
        }
        
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid.front().size();
        this->grid = grid;
        this->dp.resize(row, vvi(col, vi(col, -1)));
        
        return fun(0, 0, col - 1);
        
    }
};