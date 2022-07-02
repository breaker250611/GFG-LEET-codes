class Solution {
public:
    int combinationSum4(vector<int>& nums, int amount) {
          vector<unsigned long long int>dp(amount+1,0);
        dp[0] = 1;
            for(unsigned long long int i = 1;i<amount+1;i++){
        for(auto &it:nums){
                if(i>=it){
                    dp[i] += dp[i-it];
                    // dp[i] += max(dp[i],temp);
                }
            }
        }
        return dp[amount]= (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};