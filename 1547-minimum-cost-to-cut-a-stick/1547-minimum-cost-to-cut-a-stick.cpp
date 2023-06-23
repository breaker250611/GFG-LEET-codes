class Solution {
public:
    
    vector<vector<int>>dp;
    
    int call(vector<int>& cuts,int i,int j,int len,int beg){
        if(i>=j)return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        int &ans = dp[i][j];
        int res = INT_MAX;
        for(int k = i;k<j;k++){
            int temp = (len-beg) + call(cuts,i,k,cuts[k],beg) + call(cuts,k+1,j,len,cuts[k]);
            res = min(temp,res);
        }
        ans = res;
        return res;
    }
    int minCost(int n, vector<int>& cuts) {
     sort(cuts.begin(),cuts.end());
        // res = INT_MAX;
        dp.resize(101,vector<int>(101,-1));
        int ans = call(cuts,0,cuts.size(),n,0);
        
        return ans;
    }
};