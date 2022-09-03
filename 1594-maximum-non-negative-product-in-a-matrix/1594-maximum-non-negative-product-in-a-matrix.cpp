const int mod = 1e9+7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long int>>dp(grid.size(),vector<long long int>(grid[0].size(),1));
        dp[0][0] = grid[0][0];
        vector<vector<long long int>>dpmin = dp;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(i==0 and j==0){}
                else if(i==0){
                    dp[i][j] = dp[i][j-1]*grid[i][j];
                    dpmin[i][j] = dpmin[i][j-1]*grid[i][j];
                    
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j]*grid[i][j];
                    dpmin[i][j] = dpmin[i-1][j]*grid[i][j];
                    
                }
                else{
                    dp[i][j] = max({dp[i][j-1]*grid[i][j],dp[i-1][j]*grid[i][j],dpmin[i][j-1]*grid[i][j],dpmin[i-1][j]*grid[i][j]});
                    dpmin[i][j] = min({dp[i][j-1]*grid[i][j],dp[i-1][j]*grid[i][j],dpmin[i][j-1]*grid[i][j],dpmin[i-1][j]*grid[i][j]});

                }
            }
        }
        int maxi = dp[m-1][n-1]%mod;
        int mini = dpmin[m-1][n-1]%mod;
        return max({maxi,mini,-1});
        }
};