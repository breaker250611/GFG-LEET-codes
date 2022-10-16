//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> vp) 
    {
        	int a = vp[0];
        	int n = vp.size();
   	// b = a;
   	for(int i = 1;i<n;i++){
   		a ^= vp[i];
   	}
   	int ind = 0;
    // cout<<"a= "<<a<<endl;
    // cout<<"b = "<<b<<endl;
   	for(int i = 0;i<32;i++){
   		int peh  = (a>>i)&1;
  
   		if(peh){
   			ind = i;
   			break;
   		}
   	}
    // cout<<"ind = "<<ind<<endl;
   	int part0 = 0;
   	int part1 = 0;
   	for(int i = 0;i<n;i++){
   		int nu = vp[i];
   		int check = (nu>>ind)&1;
   		if(check==0){
   			part0 ^= nu;
            
   		}
   		else{
            // cout<<"nu = "<<nu<<endl;
   			part1 ^= nu;
   		}
   	}
   	vector<int>dp;
   	if(part0>part1){
   	    swap(part0,part1);
   	}
   	dp.push_back(part0);
   	dp.push_back(part1);
   	return dp;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends