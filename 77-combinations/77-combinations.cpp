class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i = 1;i<=n;i++){
            nums.push_back(i);
        }
        
        vector<vector<int>>ans;
        combination(0,nums,k,0,ans,{});
        return ans;
    }
    void combination(int i,vector<int>&nums,int k,int csf,vector<vector<int>>&ans,vector<int>temp){
        if(csf==k){
            ans.push_back(temp);
            return;
            
        }
        if ((nums.size()-i+1) < (k-csf))
            return;
        
        for(i;i<nums.size();i++){
            
            temp.push_back(nums[i]);
            combination(i+1,nums,k,csf+1,ans,temp);
            temp.pop_back();
        }
    }
};