//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
const long long int MOD = 1e9+7;
class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    long long int i = 2;
		    long long int x = 2;
		    for(int k = 1;k<n;k++){
		        i = (i*x+1)%MOD;
		        x++;
		    }
		    return i;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends