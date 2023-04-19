class Solution {
public:
    vector<vector<int>>ans;
    
    
    void solve(vector<int>&nums,vector<int>&temp,int i){
        
            ans.push_back(temp);
        
        for(int j = i;j<nums.size();j++){
            temp.push_back(nums[j]);
            solve(nums,temp,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>temp;
        solve(nums,temp,0);
        return ans;
    }
    
};