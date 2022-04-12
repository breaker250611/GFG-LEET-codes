class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            
            if(i==0) ans.push_back(nums[i]);
            else if(ans.back()<nums[i]) ans.push_back(nums[i]);
            else{
                int l = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[l] = nums[i];
            }
        }
        return ans.size();
    }
};