class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre;
        vector<int>suff(nums.size()+1,0);
        int pr = 1;
        pre.push_back(1);
        for(int i = 0;i<nums.size();i++){
            pr *= nums[i];
            pre.push_back(pr);
        }
        
         suff[nums.size()] = 1;
        int suf  = 1;
        for(int i = nums.size()-1;i>=0;i--){
            suf *= nums[i];
            suff[i] = suf;
        }
        
        vector<int>ans;
        
        for(int i = 0;i<nums.size();i++){
            int daalna = pre[i]*suff[i+1];
            ans.push_back(daalna);
        }
        
        return ans;
        
    }
};