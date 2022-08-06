class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>parent(nums.size(),0);
        
        int start = 0;
        int maxi = 0;
        for(int i = 1 ;i<nums.size();i++){
            parent[i] = i;
            for(int j = 0;j<i;j++){
                
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    }
                }
                if(maxi<dp[i]){
                    maxi = dp[i];
                    start = i;
                }
            }
        }
        vector<int>ans;
        while(parent[start]!=start){
            ans.push_back(nums[start]);
            start = parent[start];
        }
        ans.push_back(nums[start]);
        return ans;
    }
};