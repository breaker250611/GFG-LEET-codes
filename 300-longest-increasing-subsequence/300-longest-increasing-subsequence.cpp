class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        
        
        for(int i = 0;i<nums.size();i++){
            for(int j = 0 ;j<i;j++){
                if(nums[j]<nums[i] and dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};