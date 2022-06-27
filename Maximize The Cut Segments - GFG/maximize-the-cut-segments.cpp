// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       vector<int>dp(n+1,-10);
    dp[0] = 0;
    
    for(int i = 1;i<=n;i++){
        int temp1=-10,temp2=-10,temp3=-10;
        if(i>=x&&dp[i-x]>=0){
            temp1 = dp[i-x]+1;
        }
       if(i>=y&&dp[i-y]>=0){
            temp2 = dp[i-y]+1;
        }
        if(i>=z&&dp[i-z]>=0){
            temp3 = dp[i-z]+1;
        }
        dp[i] = max({dp[i],temp1,temp2,temp3});
    }
//     for(auto &it:dp)cout<<it<<" ";
//     cout<<endl;
    return dp[n] = (dp[n]>0)?dp[n]:0;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends