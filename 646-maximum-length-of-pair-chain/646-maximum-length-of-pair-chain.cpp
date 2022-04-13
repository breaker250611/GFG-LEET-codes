class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
     sort(pairs.begin(),pairs.end());
        
        vector<int>dp (pairs.size(),1);
        for(int i = 0;i<pairs.size();i++){
            for(int j = 0;j<i;j++){
                int c = pairs[i][0];
                int b = pairs[j][1];
                if(b<c&&dp[i]<dp[j]+1) dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};