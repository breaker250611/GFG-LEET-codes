const long long MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
       vector<long long>dp(n+1,0);
        if(n<3) return n;
        dp[1] =1 ;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4;i<=n;i++) 
            dp[i] = (dp[i-3]+2*dp[i-1])%MOD;
    return dp[n];
    }
};