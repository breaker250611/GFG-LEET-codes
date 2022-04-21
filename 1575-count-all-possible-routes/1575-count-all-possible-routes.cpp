class Solution {
     int mod = 1000000007;
public:
    int n , target;
   
    int solve (vector<int>&a , int i , int fuel , vector<vector<int>>&dp){
        
        int op = a[i] == target;
        if (fuel <= 0){
            return op;
        }
        
        if (dp[i][fuel] != -1)
            return dp[i][fuel];
        
        op = a[i] == target;
        for (int k = 0 ; k<a.size() ; k++){
            if (k != i){
                if (fuel-abs(a[i]-a[k]) >= 0){
                  op = (op + solve(a , k , fuel-abs(a[i]-a[k]) , dp))%mod;
                }
            }
        }
        return dp[i][fuel] = op;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        target = locations[finish];
        vector<vector<int>> dp(n+1 , vector<int>(fuel+1 , -1));
        return solve(locations , start , fuel , dp);
    }
};