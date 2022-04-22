class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size() , m = dungeon[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;
        for (int j = m-1 ; j>= 0 ;j--){
            for (int i = n-1 ; i>= 0 ; i--){
                    int val = dungeon[i][j] - min(dp[i][j+1], dp[i+1][j]);
                    if (val >= 0){dp[i][j] = 1;}
                    else{
                        dp[i][j] = abs(val);
                    }
                }
            }
        return dp[0][0];
    }
};;