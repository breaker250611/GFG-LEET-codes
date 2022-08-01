class Solution {
public:
    vector<vector<int>>ans;
    void call(vector<int>& nums,vector<int>&daal,int j){
        
    ans.push_back(daal);
        for(int i = j;i<nums.size();i++){
            if(i>j and nums[i]==nums[i-1])continue;
            daal.push_back(nums[i]);
            call(nums,daal,i+1);
            daal.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(),nums.end());
        vector<int>daal;
        call(nums,daal,0);
        return ans;
    }
};