const long long int MOD = 1e9 + 7;

int dr[] = {-1, 1, 0, 0}; 
int dc[] = {0, 0, -1, 1};
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+10,-1)));
       return karlega(m,n,maxMove,startRow,startColumn,dp); 
        
    }
    int karlega(int m , int n , int move,int i,int j,vector<vector<vector<int>>>&dp){
        
        if(i>=m||j>=n||i<0||j<0) return 1;
        if(move == 0) return 0;
        int &ans = dp[i][j][move];
        
        if(ans==-1){
            ans = 0;
            for(int k = 0;k<4;k++){
                ans = (ans+karlega(m , n,move-1,i+dr[k],j+dc[k],dp))%MOD;
            }
        }
        return ans;
    }
};