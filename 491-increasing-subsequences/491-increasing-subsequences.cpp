class Solution {
public:
    void solve(vector<int>&cur, vector<vector<int>>& ans, vector<int>& nums, int i){
        if(i==nums.size()){
            if(cur.size()>=2) ans.push_back(cur);
            return;
        }
        if(nums[i]==cur[cur.size()-1]){
            cur.push_back(nums[i]);
            solve(cur,ans,nums,i+1);
            cur.pop_back();
            return;
        }
        solve(cur,ans,nums,i+1);
        if(nums[i]<cur[cur.size()-1]){
            return;
        }
        else{
            cur.push_back(nums[i]);
            solve(cur,ans,nums,i+1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            vector<int> cur;
            cur.push_back(nums[i]);
            solve(cur,ans,nums,i+1);
        }
        return ans;
    }
};