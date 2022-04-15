static bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        if(a[1]==b[1]){
            return a[2]>b[2];
        }
        else{
            return a[1]>b[1];
        }
    }
        
    else {
        return a[0]>b[0];
    }
}
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
       for(int i = 0;i<cuboids.size();i++){
           vector<int> &temp = cuboids[i];
           sort(temp.begin(),temp.end());
       } 
        sort(cuboids.begin(),cuboids.end(),cmp);
        for(auto &it:cuboids){
            for(auto &j:it) cout<<j<<" ";
            cout<<endl;
        }
        int n = cuboids.size();
        vector<int>dp(n,0);
        for(int i = 0;i<n;i++) dp[i] = cuboids[i][2];
        
        for(int i =n-1;i>=0;i--){
            for(int j =n-1;j>i;j--){
            if(cuboids[i][0]>=cuboids[j][0]&&cuboids[i][1]>=cuboids[j][1]&&cuboids[i][2]>=cuboids[j][2]){
                
                if(dp[i]<dp[j]+cuboids[i][2]){
                    dp[i] = dp[j] +cuboids[i][2];
                }
            }    
            
                
            }
        }
        // for(auto &it:dp) cout<<it<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};