class Solution {
public:
    vector<vector<int>> dp;
    string s, t;
    int n, m;
    
    int fun(int i, int j) {
        if (i == n or j == m) {
            return 0;
        }
        
        int &ans = dp[i][j];
        
        if (ans == -1) {
            if (s[i] == t[j]) {
                ans = fun(i+1, j +1) + 1;
            }
            else {
                ans = max( fun(i+1, j), fun(i, j+1));
            }
        }
        return ans;
    }
    
    int longestCommonSubsequence(string s, string t) {
        this->s = s;
        this->t = t;
        n = s.size(); 
        m = t.size(); 
        
        dp.resize(n, vector<int>(m ,-1));
        
        return fun(0, 0);
        
    }
};