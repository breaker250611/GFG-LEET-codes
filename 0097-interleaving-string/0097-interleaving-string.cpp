class Solution {
public:
        vector<vector<vector<int>>>dp;
    
    int call (string &s1,string &s2,string &s3,int i , int j, int k){
        if(i==s1.size() and j == s2.size()) {
            dp[i][j][k] = 1;
            return dp[i][j][k];
        
        }
        int &ans = dp[i][j][k];
        if(ans ==-1){
            ans = 0;
            if(s1[i]==s3[k]){
                ans = max(ans,call(s1,s2,s3,i+1,j,k+1));
            }
            if(s2[j]==s3[k]){
                ans = max(ans,call(s1,s2,s3,i,j+1,k+1));
            }
        }
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        if((s1.size()+s2.size())!=s3.size() ) return false;
        int ans = call(s1,s2,s3,0,0,0);
        ans = dp[s1.size()][s2.size()][s3.size()];
        if(ans==1)return true;
        return false;
    }
};