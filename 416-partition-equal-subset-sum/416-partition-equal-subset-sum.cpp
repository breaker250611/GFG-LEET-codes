class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2!=0) return false;
        
        sum /=2;
        
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
        // for(auto &x:dp){
        //     for(auto &y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[nums.size()][sum];
    }
};