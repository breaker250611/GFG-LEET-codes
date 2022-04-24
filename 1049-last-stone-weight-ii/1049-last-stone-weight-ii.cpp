class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      int sum = accumulate(stones.begin(),stones.end(),0);
      int ans = 0;
       ans = check(stones,sum);
        return ans;
    
    }
    
    int check(vector<int>& nums,int sum){
                vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,0));

        for(int i = 0;i<=nums.size();i++){
            for(int j  = 0;j<=sum;j++){
                if(i==0&&j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]= 0;
                else{
                    int upar = dp[i-1][j];
                    int peeche = 0;
                    if(j>=nums[i-1]) peeche = dp[i-1][j-nums[i-1]];
                    
                    dp[i][j] = max(upar,peeche);
                }
            }
        }
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<=sum;i++){
            if(dp[n][i]){
                ans = min(ans,abs(sum-(i)-i));
            }
        }
        return ans;
    }
};