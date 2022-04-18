class Solution {
public:
    int longestPalindromeSubseq(string s) {
          string sec= s;
        reverse(s.begin(),s.end());
        int maxi = 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        
        for(int i = s.size()-1;i>=0;i--){
            for(int j = s.size()-1;j>=0;j--){
                if(sec[i]==s[j]){
                     dp[i][j] = 1+dp[i+1][j+1];
                  
                }
                else{
                    int a = dp[i+1][j];
                    int b = dp[i][j+1];
                    dp[i][j]= max(a,b);
                }
                if(maxi<dp[i][j]) maxi = dp[i][j];
            }
        }
        // for(auto &it:dp){
        //     for(auto &x:it) cout<<x<<" ";
        //     cout<<endl;
        // }
        return maxi;
    }
};