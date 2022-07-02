class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(auto &it:coins){
            for(int i = 1;i<amount+1;i++){
                if(i>=it&&dp[i-it]!=INT_MAX){
                    int temp = dp[i-it]+1;
                    dp[i] = min(dp[i],temp);
                }
            }
        }
        return dp[amount]= (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};