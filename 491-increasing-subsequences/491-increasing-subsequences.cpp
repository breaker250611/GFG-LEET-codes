class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void call(vector<int>&nums,int i , vector<int>temp){
        if(temp.size()>1){
            st.insert(temp);
        }
        
        if(i==nums.size())return;
        
        for(int k = i;k<nums.size();k++){
            if(temp.size()>0 and temp.back()>nums[k])continue;
            if(k>i and nums[k]==nums[k-1]) continue;
            temp.push_back(nums[k]);
            call(nums,k+1,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
     
        
          call(nums,0,{});
        for(auto &it:st) ans.push_back(it);
        return ans;
    }
};