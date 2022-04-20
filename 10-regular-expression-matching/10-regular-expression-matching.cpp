/*
                    ""
                    abc*
1st 
a    a    b  (i==n) ->  n 
c*   a*   b    ->  m 
  ^

aaaac
^
.*
  ^
  
  aaaa
  ..


2nd
aaaac
 ^   
.*
^
3rd
ba
 ^
.a
 ^
 
 aaaa  match = false
     ^
 ....*     bc
    ^      ^
 
*/
class Solution {
public:
    int n , m;
    bool solve(string&s,string&p ,int i ,int j , vector<vector<int>>&dp){
       
        if (i >= n and j >= m) {
             return true;
        }
        if (j >= m) return false;
      
        if (dp[i][j] != -1)
            return dp[i][j];
        
        bool match = (i < n && (s[i] == p[j] or p[j] == '.'));
        
        
          bool op1 = false , op2 = false , op3 = false;
        if (j+1 < m and p[j+1] == '*'){
          
            op1 = op1 or solve(s , p , i , j+2 , dp);
            op2 = op2 or (match ? solve(s , p , i+1,  j, dp) : false);
        }
        
        if (match){
            op3 = op3 or solve(s , p , i+1 , j+1 , dp);
        }
        return dp[i][j] = (op1 or op2 or op3);
    }
    
    bool isMatch(string s, string p) {
       
        n = s.size() , m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1 ,-1));
        return solve(s , p , 0 , 0 , dp);    
    }
};