class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 and j==0)dp[i][j]=1;
                else if(i==0) dp[i][j] = 1;
                else if (j==0) dp[i][j] = 1;
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        // for(auto&it:dp){
        //     for(auto&i:it)cout<<i<<" ";
        //     cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};