class Solution {
public:
    vector<vector<int>>dp;
    int call(int i ,int j , vector<int>&nums){
        
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MIN;
        for(int k = i ;k<=j;k++){
            int temp = nums[k]*nums[i-1]*nums[j+1] + call(i,k-1,nums)+call(k+1,j,nums);
            ans = max(temp,ans);
        }
        dp[i][j] = ans;
        return ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        
        dp.resize(301,vector<int>(301,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int ans = call(1,nums.size()-2,nums);
        return ans;
    }
};