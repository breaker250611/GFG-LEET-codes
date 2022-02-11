class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size()-1;
        vector<int>dp;
        dp = grid[n];
        
        for(int i=n-1;i>=0;i--){
            int firstmin = INT_MAX, secondmin = INT_MAX,firstmindex;
            
            for(int j=0;j<=n;j++){
                if(dp[j]<firstmin) {
                    firstmin = dp[j]; 
                    firstmindex = j;
                }
                
                }
            for(int j = 0;j<=n;j++){
                if(j!=firstmindex){
                    if(dp[j]<secondmin) secondmin = dp[j];
                }
            }
            for(int j=0;j<=n;j++){
                if(j==firstmindex){
                    dp[j]= grid[i][j]+secondmin;
                }
                else dp[j]=grid[i][j]+firstmin;
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};