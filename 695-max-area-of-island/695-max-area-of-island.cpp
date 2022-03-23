class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area = dfs(grid,i,j);
                    maxarea = max(area,maxarea);
                }
    }
        }
        return maxarea;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) return 0;
        grid[i][j]=0;
        int ans = 0;
        ans +=dfs(grid,i+1,j);
        ans +=dfs(grid,i,j+1);
        ans +=dfs(grid,i-1,j);
        ans +=dfs(grid,i,j-1);
        return ans+1;

    }
};