//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const long long int MOD = 1e8;

class Solution {
  public:
    int fillingBucket(int N) {
        vector<int>bott = {1,2};
        
        vector<int>dp(N+1,0);
        dp[0] =1  ;
        
        for(int i = 1;i<=N;i++){
            for(int j = 0;j<2;j++){
                if(i>=bott[j]){
                    dp[i] += dp[i-bott[j]]%MOD;
                    dp[i] = dp[i]%MOD;
                }
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends