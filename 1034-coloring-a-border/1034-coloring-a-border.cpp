int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int prnt = grid[row][col];
        dfs(grid,row,col,prnt);
        
        for(auto &it:grid){
            for(auto &v:it){
                if(v<0) v = color;
            }
        }
        return grid;
    }
    void dfs(vector<vector<int>>& grid, int i, int j,int prnt){  
        grid[i][j] = -prnt;
        int count = 0;
        for(int d = 0;d<4;d++){
            int nr = i+dr[d];
            int nc = j +dc[d];
            if(nr<0||nc<0||nr>=grid.size()||nc>=grid[0].size()||abs(grid[nr][nc])!=prnt){
                continue;
            }
            
            count++;
            if(grid[nr][nc]>0){
                dfs(grid,nr,nc,prnt);
            }
        }
        if(count==4) grid[i][j] = abs(grid[i][j]);
    }
};