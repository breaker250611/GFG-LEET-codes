//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        map<int,int>mp;
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<N){
            mp[arr[i]]++;
            while((mp.rbegin()->first-mp.begin()->first)>1){
                mp[arr[j]]--;
                if(mp[arr[j]]==0){
                    mp.erase(arr[j]);
                }
                j++;
            }
            count = max(count,i-j+1);
            
            i++;
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends