class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
     vector<int>dp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            auto it = upper_bound(ans.begin(),ans.end(),nums[i]);
            
            if(it==ans.end()) {
                ans.push_back(nums[i]);
                dp.push_back((int)ans.size());
            }
                else{
                int merapehelwaan = it-ans.begin();
                ans[merapehelwaan] = nums[i];
                dp.push_back(merapehelwaan+1);
            }
        }
        return dp;
    }
};