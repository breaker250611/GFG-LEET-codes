class Solution {
public:
    
    int integerBreak(int n) {
        vector<int>nums;
        for(int i = 1;i<n;i++)nums.push_back(i);
        vector<vector<int>>dp(nums.size()+1,vector<int>(n+1,-1));
        int ans = call(n,nums,0,0,dp);
    return ans;
    }
    
    int call(int n,vector<int>& nums,int i,int sum, vector<vector<int>>&dp){
        
        if(sum==n){
            return 1;
        }
        else if(sum>n||i>=nums.size()) return 0;
        
        int &ans = dp[i][sum];
        if(ans!=-1){
            return ans;
            }
        else{
            return ans = max(call(n,nums,i,sum+nums[i],dp)*nums[i],call(n,nums,i+1,sum,dp));
        }
    }
};