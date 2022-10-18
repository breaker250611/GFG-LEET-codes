//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		vector<int>ans;
		
		int i = 0;
		int j = 0;
		
		for(int k = 0;k<(2*N-1);k++){
		    int ni = i;
		    int nj= j;
		    while(ni<=N-1 and nj>=0){
		        ans.push_back(A[ni][nj]);
		        ni++;
		        nj--;
		    }
		    
		    
		    if(j<N-1){
		        j++;
		    }
		    else if(i<N-1){
		        i++;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends