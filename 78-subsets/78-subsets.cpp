class Solution {
public:
    vector<vector<int>>ans;
    void call(vector<int>& nums,vector<int> &daal,int i){
        
        if(i==nums.size()){
            ans.push_back(daal);
            return;
        }
        
        call(nums,daal,i+1);
        daal.push_back(nums[i]);
        call(nums,daal,i+1);
        daal.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> daal;
        ans.clear();
        call(nums,daal,0);
        return ans;
    }
};