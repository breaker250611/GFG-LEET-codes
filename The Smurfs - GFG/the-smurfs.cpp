//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        vector<int>vp(3,0);
        for(int i = 0;i<n;i++){
            char c = a[i];
            if(c=='R'){
                vp[0]++;
            }
            else if(c=='B'){
                vp[1]++;
            }
            else{
                vp[2]++;
            }
        }
         if(vp[0]==n or vp[1]==n or vp[2]==n){
            return n;
        }
       if(vp[0]==0 or vp[1]==0 or vp[2]==0){
           vp[1] = max({vp[0],vp[1],vp[2]});
           vp[2] = n-vp[1];
           if(vp[0]%2==0 and vp[1]%2==0){
               return 2;
           }
           else return 1;
       }
       int peh = max({vp[0],vp[1],vp[2]});
       int sec = min({vp[0],vp[1],vp[2]});
       int khatam = n-peh-sec;
       
        peh = sec+peh;
        sec = khatam-sec;
        
        if(peh%2==0 and sec%2==0){
               return 2;
           }
           else return 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends