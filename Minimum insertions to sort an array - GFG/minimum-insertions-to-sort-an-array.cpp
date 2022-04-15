// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minInsertions(int arr[], int N) 
	{ 
	    vector<int>dp(N,1);
	    for(int i =0;i<N;i++){
	        for(int j = 0;j<i;j++){
	            if(arr[i]>=arr[j]&&dp[i]<dp[j]+1) dp[i]= dp[j]+1;
	        }
	    }
	    int m =  *max_element(dp.begin(),dp.end());
	    return N-m;
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	   

	    Solution ob;
	    cout << ob.minInsertions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends