class Solution {
public:
    int ans = 0;
    
    void call(int n,vector<vector<int>>&requests,int i,vector<int>&dp,int cnt){
        if(i==requests.size()){
            for(int k = 0;k<n;k++){
                if(dp[k]!=0)return ;
            }
            ans = max(ans,cnt);
            return;
        }
        
        call(n,requests,i+1,dp,cnt);
        
        dp[requests[i][0]]--;
        dp[requests[i][1]]++;
        call(n,requests,i+1,dp,cnt+1);
        dp[requests[i][0]]++;
        dp[requests[i][1]]--;
        
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        ans = INT_MIN;
        vector<int>dp(n,0);
        call(n,requests,0,dp,0);
        
        return ans;
    }
};