// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int n){
        vector<long long int>dp(n+1,0);
        for(int i = 1;i<=n;i++){
            if(i<4) dp[i] = 1;
            else if(i==4)dp[i] = 2;
            else{
                dp[i] = dp[i-1]+dp[i-4];
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends