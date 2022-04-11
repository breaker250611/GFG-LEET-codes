class Solution {
public:
    int numSquares(int n) {
        vector<int>nums;
        for(int i = 1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<nums.size();j++){
                int num = nums[j];
                if(i>=num){
                    if(dp[i]==-1&&dp[i-num]!=-1){
                        dp[i] = dp[i-num]+1;
                    }
                    else if(dp[i-num]>-1){
                        dp[i] = min(dp[i],dp[i-num]+1);
                    }
                }
            }
        }
//         for(auto &it:nums)cout<<it<<" ";
//         cout<<endl;
        
//         for(auto &it:dp)cout<<it<<" ";
//         cout<<endl;
        return dp[n];
    }
};