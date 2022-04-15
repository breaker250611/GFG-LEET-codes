
class Solution {
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>vp;
        vector<int>dp;
        for(int i = 0;i<ages.size();i++){
            vp.push_back({ages[i],scores[i]});
            
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<vp.size();i++){
            dp.push_back(vp[i][1]);
        }
        for(int i =0;i<ages.size();i++){
            for(int j=0;j<i;j++){
                if(vp[i][1]>=vp[j][1]&&dp[i]<dp[j]+vp[i][1]){
                    dp[i]=dp[j]+vp[i][1];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};