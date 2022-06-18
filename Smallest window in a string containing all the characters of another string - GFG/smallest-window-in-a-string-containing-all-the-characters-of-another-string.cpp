// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
     public:
    
    bool fun(const vector<int>& hash_s, const vector<int>& hash_p) {
        for (int i = 0; i < 26; i++) {
            if (hash_s[i] < hash_p[i]) {
                return false; 
            }
        }
        return true; 
    }
    
    string smallestWindow (string s, string p) {
        
        string ans; 
        int res = INT_MAX; 
        int l = 0; 
        int start = -1; 
        int end = -1; 
        
        vector<int> hash_p(26, 0), hash_s(26, 0); 
        
        for (const auto& i: p) {
            hash_p[i - 'a'] ++; 
        }
        
        for (int r = 0; r < s.size(); r++) {
            hash_s[s[r] - 'a'] ++;
            
            bool flag = fun(hash_s, hash_p); 
            while (l <= r && flag) {
                if (flag && r - l + 1 < res) {
                    res = r - l + 1; 
                    start = l; 
                    end = r; 
                }
                
                hash_s[s[l] - 'a'] --; 
                l ++; 
                
                flag = fun(hash_s, hash_p); 
            }
        }
        // ans = s.substr(start, res);
        for (int i = start; i <= end; i++) {
            if ('a' <= s[i] && s[i] <= 'z')
                ans.push_back(s[i]);
        }
        
        return ans.empty() ? "-1" : ans; 
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends