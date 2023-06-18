class Solution {
public:
    const long long int mod = 1e9+7;
    vector<vector<int>>dp;
    
    
    int call(int i ,int j,vector<vector<int>>&grid,int prev){
        
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return 0;
        if(prev >= grid[i][j])return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        
        int val = grid[i][j];
        int top = call(i-1,j,grid,val);
        int down = call(i+1,j,grid,val);
        int left = call(i,j-1,grid,val);
        int right = call(i,j+1,grid,val);
        
        
        dp[i][j] =  ((top+down+left+right)%mod+1)%mod;
        return dp[i][j];
    }
    
    int countPaths(vector<vector<int>>& grid) {
        dp.resize(1001,vector<int>(1001,-1));
        int ans = 0;
        
        
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                ans = (ans+(call(i,j,grid,-1))%mod)%mod;
            }
        }
        return ans;
    }
};