// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<int>dp(W+1,0);
       dp[0] = 0;
       for(int i = 1;i<=W;i++){
           for(int j = 0;j<N;j++){
               int pric = val[j];
               int wei = wt[j];
               int temp ;
               if(i>=wei){
                    temp = dp[i-wei]+pric;
               }
               dp[i] = max(temp,dp[i]);
           }
       }
    //   for(auto &x:dp)
    //   cout<<x<<" ";
    //   cout<<endl;
      return dp[W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends