const long long int MOD = 1e9 + 7;

class Solution {
public:
   vector<int>dp;
    int call(vector<int>&arr, int k ,int i){
        int n = arr.size();
        if(i==n) return 0;
        
        if(dp[i]!=-1)return dp[i];
        int cnt=0;
        int maxi = 0;
        int ans = 0;
        int limit = min(i+k,n);
        for(int j = i;j<limit;j++){
            cnt++;
            maxi = max(maxi,arr[j]);
            int temp = maxi*cnt + call(arr,k,j+1);
            ans = max(ans,temp);
        }
        dp[i] = ans;
        return ans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        int ans = call(arr,k,0);
        
        return ans;
    }
};