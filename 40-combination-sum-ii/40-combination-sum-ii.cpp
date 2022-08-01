class Solution {
public:
    vector<vector<int>>ans;
 
    
    void call(vector<int>& candidates, int target,int i,int sum,vector<int>&daal){
        if(target==sum){

            ans.push_back(daal);
            return;
        }
        if(i>=candidates.size()) return;
        if(target<sum)return;
        
        for(int j = i;j<candidates.size();j++){
            if(j>i and candidates[j-1] == candidates[j]) continue;
            
            daal.push_back(candidates[j]);
            call(candidates,target,j+1,sum+candidates[j],daal);
            daal.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(),candidates.end());
        vector<int>daal;
        call(candidates,target,0,0,daal);
        // for(auto &it:st){
        //     ans.push_back(it);
        // }
        return ans;
    }
};