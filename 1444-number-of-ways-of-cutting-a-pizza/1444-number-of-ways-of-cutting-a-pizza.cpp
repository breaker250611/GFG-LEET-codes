class Solution {
public:
    const long long int mod = 1e9+7;
    int dp[100][100][100];
    
    int call(vector<vector<int>>&pizz,int r,int c,int remain,int n,int m){
        
        if(remain==0){
            // cout<<"c"<<endl;
            if(pizz[r][c]==0)return 0;
            else {
                // cout<<"c"<<endl;
                return 1;}
        }
        
        int &ans = dp[r][c][remain];
        if(ans!=-1)return ans;
        ans = 0;
        for(int i = r+1;i<n;i++){
            if(pizz[i][c]>remain-1 and pizz[i][c]<pizz[r][c]){
                ans  = (ans%mod + call(pizz,i,c,remain-1,n,m)%mod)%mod;
            }
        }
        for(int j = c+1;j<m;j++){
            if(pizz[r][j]>remain-1 and pizz[r][j]<pizz[r][c]){
                ans = (ans%mod +call(pizz,r,j,remain-1,n,m)%mod)%mod;
            }
        }
        return ans;
    }
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>>pizz(pizza.size(),vector<int>(pizza[0].size(),0));
        int n = pizza.size();
        int m = pizza[0].size();
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(j+1<m){
                    pizz[i][j] = pizz[i][j+1];
                }
                if(i+1<n and pizz[i+1][j]>0){
                    pizz[i][j] += pizz[i+1][j];
                }
                if(j+1<m and i+1<n){
                    pizz[i][j] -= pizz[i+1][j+1];
                }
                if(pizza[i][j]=='A')pizz[i][j]++;
            }
        }
        
        // for(auto&it:pizz){
        //     for(auto &x:it)cout<<x<<" ";
        //     cout<<endl;
        // }
        // return 0;
        dp[n+1][m+1][k];
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                for(int l = 0;l<k;l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        int ans = call(pizz,0,0,k-1,n,m);
        // for(int i = 0;i<=n;i++){
        //     for(int j = 0;j<=n;j++){
        //         for(int l = 0;l<k;l++){
        //            cout<<dp[i][j][l]<<" "; 
        //             }
        //     }
        // }
        return ans;
    }
};