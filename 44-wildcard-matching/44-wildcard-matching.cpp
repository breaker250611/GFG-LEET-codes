class Solution {
public:
    int n , m;
    bool solve(string &s , string &p ,int i , int j , vector<vector<int>>&dp){
        if (i == n){
            //cout << j << "\n";
          for (int k = j ; k<m ;k++){
              if (p[k] != '*') return false;
           }
           return true;
        }
        if (j == m)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] or p[j] == '?'){
           return dp[i][j] = solve(s , p , i+1 , j+1 , dp);
        }
        if (p[j] == '*'){
            return dp[i][j] = (solve(s , p , i+1 , j,dp) or solve(s , p , i , j+1,dp));
        }
        else
            return dp[i][j] = false;
    }
    
    
    bool isMatch(string s, string p) {
           n = s.size() , m = p.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return solve(s , p , 0, 0 , dp);
    }
};