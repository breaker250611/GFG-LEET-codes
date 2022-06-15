// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
 
    bool good (vector<vector<int>> &matrix , int val , int k){
        
       int count = 0;    
       for (auto x : matrix){
           auto it = upper_bound(x.begin() , x.end() , val)-x.begin();
           count += it;
       }        
       return count >= k;
    }
 
    int median(vector<vector<int>> &matrix, int r, int c){
        
        int k = (r*c+1)/2;
        
        int low = INT_MAX  , high = INT_MIN;
        for (int i = 0 ; i < r ; i++){
            low  = min(matrix[i][0] , low);
            high = max(matrix[i][c-1] , high );
        }
        int ans = -1;
        while (low <= high){
            int mid = (low + high)/2;
            
            if (good(matrix , mid , k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends