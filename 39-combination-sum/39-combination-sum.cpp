class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n = candidates.size();
        vector<int>dp(target+1,0);
        
        dp[0]=1;
        for(int i=1;i<target+1;i++){
            for(int j = 0;j<candidates.size();j++){
                int coin = candidates[j];
                if(coin > i) continue;
                if(dp[i-coin]==1){
                    dp[i]=1;
                    break;
                }
            }
        }
        for(auto &it:dp)cout<<it<<endl;
        
    vector<vector<int>>ans;
        
        karlunga(candidates,target,ans,{},dp,0);
        return ans;
    }
    void  karlunga(vector<int>&coin , int target,vector<vector<int>>&ans,vector<int>temp,vector<int>&dp,int i){
        
            if(target==0){
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        
        for( i;i<coin.size();i++){
            int co = coin[i];
            if(target>=co){
                if(dp[target-co]==1){
                    temp.push_back(co);
                    karlunga(coin,target-co,ans,temp,dp,i);
                    temp.pop_back();
                }
            }
        }
        
    }
    
    
};