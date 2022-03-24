class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1){
                    if(grid1[i][j]==1){
                        count +=dfs(grid1,grid2,i,j);
                    }
                }
            }
        }
        return count;
    }
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0||j<0||i>=grid1.size()||j>=grid2[0].size()||grid2[i][j]==0) return 1;
        if(grid1[i][j]==0) return 0;
        grid2[i][j]=0;
        
        int ans =  min({dfs(grid1,grid2,i-1,j),dfs(grid1,grid2,i,j-1),dfs(grid1,grid2,i,j+1),dfs(grid1,grid2,i+1,j)});
    return ans;
    }
};