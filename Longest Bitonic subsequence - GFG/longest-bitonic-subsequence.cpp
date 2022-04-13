// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int>suff(nums.size(),1);
	    vector<int>preff(nums.size(),1);
	    
	    for(int i = 0;i<nums.size();i++){
	        for(int j = 0;j<i;j++){
	            if(nums[i]>nums[j]&&suff[i]<suff[j]+1){
	                suff[i] = suff[j]+1; 
	            }
	        }
	    }
	    for(int i = nums.size()-1;i>=0;i--){
	        for(int j = nums.size()-1;j>i;j--){
	            if(nums[i]>nums[j]&&preff[i]<preff[j]+1){
	                preff[i] = preff[j]+1;
	            }
	        }
	    }
	   // for(auto &it:suff) cout<<it<<" ";
	   // cout<<endl;
	   // for(auto &it:preff) cout<<it<<" ";
	   // cout<<endl;
	    int max = 0;
	   // reverse(preff.begin(),preff.end());
	    for(int i =0;i<preff.size();i++ ){
	        int temp = suff[i]+preff[i];
	        if(temp>max) max = temp;
	    }
	    return max-1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends