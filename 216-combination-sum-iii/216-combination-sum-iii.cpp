class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=9;i++) nums.push_back(i);
        
        combi(nums,k,n,0,ans,{},0);
        return ans;
    }
    void combi(vector<int>&nums,int k,int target,int psf,vector<vector<int>>&ans,vector<int>temp,int i){
        if(target==0&&psf==k){
            ans.push_back(temp);
            return;
        }
        else if((psf<k&&target==0))return;
        else if(psf>k)return;
        for(i;i<nums.size();i++){
            if(i<=target){
                temp.push_back(nums[i]);
                combi(nums,k,target-nums[i],psf+1,ans,temp,i+1);
                temp.pop_back();
            }
            else break;
        }
    }
};