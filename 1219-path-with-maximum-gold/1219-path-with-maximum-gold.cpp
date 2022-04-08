class Solution {
public:
    int mxans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        mxans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    holihai(grid,i,j,0);
                }
            }
        }
        return mxans;
    }
    void holihai(vector<vector<int>>&grid,int i,int j ,int ans){
        
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) return;
        
        ans+=grid[i][j];
        mxans = max(ans,mxans);
        int temp = grid[i][j];
        grid[i][j]=0;
        holihai(grid,i+1,j,ans);
        holihai(grid,i-1,j,ans);
        holihai(grid,i,j-1,ans);
        holihai(grid,i,j+1,ans);    
    grid[i][j]=temp;
    }
};