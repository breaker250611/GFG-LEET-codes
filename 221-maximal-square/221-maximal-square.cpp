class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int dp[matrix.size()][matrix[0].size()];
        int ans = 0;
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = matrix[0].size()-1;j>=0;j--){
                if(i==matrix.size()-1||j==matrix[0].size()-1){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else{
                    if(matrix[i][j]=='0') 
                    {dp[i][j]=0;}
                    else
                    {dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;}
                    
                }
                if(dp[i][j]>ans) ans = dp[i][j];
            }
        }
        // int ans = 0;
        // for(int i = matrix.size()-1;i>=0;i--){
        //     for(int j = matrix[0].size()-1;j>=0;j--){
        //         if(ans<dp[i][j]) ans = dp[i][j];
        //     }
        //     }
        return ans*ans;
    }
};