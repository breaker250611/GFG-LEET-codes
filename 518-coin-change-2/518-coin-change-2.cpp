class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        
        for(int i = 0;i<coins.size();i++){
            for(int j = 1;j<=amount;j++){
                int pric = coins[i];
                if(pric<=j&&dp[j-pric]>0){
                    dp[j] += dp[j-pric];
                }
            }
        }
        return dp[amount];
        
    }
};