// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
// int n = 0;
  public:
	int minDifference(int arr[], int n)  { 
	    int ans = 0;
	    int sum = accumulate(arr,arr+n,0);
	    ans = check(arr,sum,n);
	
	    return ans;
	} 
	int check(int nums[],int sum,int n){
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

        for(int i = 0;i<=n;i++){
            for(int j  = 0;j<=sum;j++){
                if(i==0&&j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]= 0;
                else if(j==0) dp[i][j]= 1;
                else{
                    int upar = dp[i-1][j];
                    int peeche = 0;
                    if(j>=nums[i-1]) peeche = dp[i-1][j-nums[i-1]];
                    
                    dp[i][j] = max(upar,peeche);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<=sum;i++){
            if(dp[n][i]==true){
                ans = min(ans,abs(sum-2*i));
            }
        }
        return ans;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends