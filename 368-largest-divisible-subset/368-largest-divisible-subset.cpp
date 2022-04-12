class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
                    if(nums[i]%nums[j]==0||nums[j]%nums[i]==0){
                        dp[i] = dp[j]+1;
                    }
                }
            }
        }
        vector<int>ans;
        int max =*max_element(dp.begin(),dp.end()); 
        cout<<max<<endl;
        for(int i = nums.size()-1;i>=0&&max>0;i--){
            int ans1 = 0;
            if(ans.size()!=0)
                  ans1 = ans.back();
            if(max==dp[i]){
                max--;
                ans.push_back(nums[i]);
    
               
            }
            int ans2 =0;
            // cout<<ans1<<" "<<ans2<<endl;
            if(ans.size()!=0)
            ans2 = ans.back();
            cout<<ans1<<" "<<ans2<<endl;

            if((ans1!=0||ans2!=0)&& (ans1%ans2!=0&&ans2%ans1!=0)) {
                ans.pop_back();
                max++;
            }
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};