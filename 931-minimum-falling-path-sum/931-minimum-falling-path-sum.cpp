class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix[0].size();
        int dp[n][n];
        for(int i = n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1) 
                    dp[i][j]=matrix[i][j];
                else if(j==n-1){
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j-1])+matrix[i][j];
                    
                }
                else if(j==0)
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+matrix[i][j];
            else {
        dp[i][j] = min({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]})+matrix[i][j];

            }
            }
        }
        for(int i=0;i<n ;i++){
            if(dp[0][i]<ans) ans = dp[0][i];
        }
        return ans;
    }
};