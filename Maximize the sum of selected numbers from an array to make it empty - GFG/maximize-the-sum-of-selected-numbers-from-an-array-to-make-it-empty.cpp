//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
    vector<int> ok(100005 , 0);
        for (int i = 0 ; i < n ; i++){
            ok[a[i]]++;
        }
        int ans = 0;
        for (int i = 100004 ; i >= 0 ; i--){
            if (ok[i] > 0){
                ans += ok[i]*i;
                ok[i-1] -= ok[i];
            }
        }
        return ans;    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends