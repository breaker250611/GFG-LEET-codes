class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        
        dp[0] =0;
        
        for(int i = 1;i<=amount;i++){
            for(int j = 0;j<coins.size();j++){
                int pric = coins[j];
                if(i>=pric&&dp[i] == -1){
                    if(dp[i-pric]>-1){
                        dp[i] = dp[i-pric]+1;
                    }
                }
                else if(i>=pric&&dp[i]>-1){
                    if(dp[i-pric]>-1){
                        dp[i] = min(dp[i],dp[i-pric]+1);
                    }
                }
            }
        }
        return dp[amount];
    }
};