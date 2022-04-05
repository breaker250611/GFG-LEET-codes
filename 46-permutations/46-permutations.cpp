class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<bool>check(nums.size(),false);
        kardunga(nums,ans,{},check);
        return ans;
    }
    
    void kardunga(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,vector<bool>&check){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i = 0;i<nums.size();i++){
            if(check[i]==false){
                check[i]=true;
                temp.push_back(nums[i]);
                kardunga(nums,ans,temp,check);
                check[i]=false;
                temp.pop_back();
            }
        }
    }
};