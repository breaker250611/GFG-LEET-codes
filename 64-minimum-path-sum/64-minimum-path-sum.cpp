class Solution {
public:
    vector<vector<int>>grid;
    vector<vector<int>>dp;
    int call(int i ,int j){
        
        if(i==0 and j==0){
            return dp[i][j] = grid[i][j];
        }
        else if(i<0 or j<0)return INT_MAX;
        int &ans = dp[i][j];
        if(ans != -1)return ans;
        
        ans = min(call(i-1,j),call(i,j-1))+grid[i][j];
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        this->grid = grid;
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
       return call(grid.size()-1,grid[0].size()-1);
        // for(auto &it:dp){
        //     for(auto &i:it)cout<<i<<" ";
        //     cout<<endl;
        // }
        
        return 0;
    }
};