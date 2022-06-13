// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++
class Solution 
{
    public:
    bool calc(int A[] , int N , int n , int thershold){
        int person = 1;
        int sum = 0;
        for (int i = 0 ; i < N  ; i++){
            if (A[i] > thershold) return false;
            if (sum + A[i] > thershold){
                person += 1;
                sum = A[i];
            }
            else{
                sum += A[i];   
            }
        }
        if (person > n) return false;
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int sum = 0;
        for (int i = 0 ; i < N ; i++){
            sum += A[i];
        }
        int ans = 0;
        int minimum = 0 , maximum = sum;
        while (minimum <= maximum){
            
            int middle = (minimum + maximum)/2;
            if (calc(A , N , M , middle)){
                ans = middle;
                maximum = middle-1;
            }
            else{
                minimum = middle+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends