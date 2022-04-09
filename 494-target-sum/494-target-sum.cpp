class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int tot = sum+target;
        if(tot%2!=0||tot<0) return 0;
        int trgt = tot/2;
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(trgt+1,0));
        
        for(int i = 0;i<dp.size();i++){
            for(int j = 0;j<dp[0].size();j++){
                if(j==0&&i==0) dp[i][j]=1;
                // else if(j==0) dp[i][j] +=
                else if(i==0) dp[i][j] = 0;
                else{
                    dp[i][j] += dp[i-1][j];
                    int num = nums[i-1];
                    if(num<=j){
                        dp[i][j] += dp[i-1][j-num];                    }
                }
                
            }
        }
        return dp[nums.size()][trgt];
    }
};