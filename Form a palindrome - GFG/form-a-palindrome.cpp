// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
     string s = str;
     reverse(s.begin(),s.end());
     int n = str.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
     int maxi = 0;
     for(int i = n-1;i>=0;i--){
         for(int j = n-1;j>=0;j--){
             if(str[i]==s[j]) dp[i][j] = dp[i+1][j+1]+1;
             else{
                 dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
             }
             if(maxi<dp[i][j]) maxi = dp[i][j];
         }
     }
     return n-maxi;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends