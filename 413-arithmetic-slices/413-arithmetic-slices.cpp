class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        if(nums.size()<3) return 0;
        else{
            for(int i= 2;i<nums.size();i++){
                if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]){
                    dp[i] = 1+dp[i-1];
                    cout<<dp[i]<<endl;
                }
                
            }
            int sum = 0;
                return sum= accumulate(dp.begin(),dp.end(),0);
        }
        return 0;
    }
};