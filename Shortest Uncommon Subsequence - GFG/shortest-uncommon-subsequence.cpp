// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
if(S==T)
            return -1;
        int n = S.length();
        int m = T.length();
        
        vector<int> next(m+1,1e9),curr(m+1,1e9);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int k = j;
                for(;k>=0;k--)
                    if(S[i]==T[k])
                        break;
                if(k<0)
                    next[j+1] = 1;
                else
                    next[j+1] = min(curr[j+1],1+curr[k]);
            }
            curr = next;
        }
        if(next[m]>=1e9)
            return -1;
        return next[m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends