class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long >>dp(s.size()+1,vector<unsigned long long int>(t.size()+1,0));
        
        dp[s.size()][t.size()]=1;
        
        for(int i = s.size()-1;i>=0;i--){
            for(int j = t.size();j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};