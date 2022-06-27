// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    #define ll long long
    const ll MOD = 1e9 + 7;

#define ld long double
    long long countWays(int n, int k){
         // Write your code here.
    if(n==1) return k;
    long long int ii = k;
    ll ij = k*(k-1);
    ll tot = ii + ij;
    for(int i = 3;i<=n;i++){
        ll nii = ij%MOD;
        ll nij = tot*(k-1)%MOD;
        ll ntot = (nij+nii)%MOD;
        
        ij = nij;
        ii = nii;
        tot = ntot;
    }
    return tot;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends