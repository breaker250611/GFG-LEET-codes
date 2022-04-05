class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        meraloda(nums,0,{},ans);
        return ans;
    }
    void meraloda(vector<int>& nums,int i , vector<int> temp,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        meraloda(nums,i+1,temp,ans);
        temp.push_back(nums[i]);
        meraloda(nums,i+1,temp,ans);
        }
    
};