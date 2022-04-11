class Solution {
public:
    int integerBreak(int n) {
        vector<int>nums;
        for(int i = 1;i<n;i++) nums.push_back(i);
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j = 0;j<nums.size();j++){
                int temp = nums[j];
                if(temp<=i){
                    dp[i] = max(dp[i],dp[i-temp]*temp);
                }
            }
        }
        for(auto &it:dp)cout<<it<<" ";
        cout<<endl;
        return dp[n];
    }
};