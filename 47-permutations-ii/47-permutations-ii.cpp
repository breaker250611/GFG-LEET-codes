class Solution {
public:
        map<vector<int>,int>mp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        mp.clear();
        call(nums,0,nums.size(),ans);
        return ans;
    }
    void call(vector<int>& nums,int i ,int n,vector<vector<int>>&ans){
        if(i==n){
            if(mp.find(nums)==mp.end()){
               mp[nums]++;
            }
            else return;
            ans.push_back(nums);
            return;
        }
        
        for(int j = i;j<n;j++){
            swap(nums[i],nums[j]);
            // string str = "";
            // for(int k = 0;k<n;k++){
            //     str += to_string(nums[i]);
            // }
            
            if(true){
                
                call(nums,i+1,n,ans);
            } 
            swap(nums[i],nums[j]);
        }
    }
};