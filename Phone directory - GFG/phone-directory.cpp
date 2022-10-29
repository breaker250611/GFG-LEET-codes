//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contacts[], string s)
    {
        // code here
        int n1=s.size();
        set<string>st;
        for(int i=0;i<n;i++)
        st.insert(contacts[i]);
        vector<vector<string>>a;
        for(int i=0;i<n1;i++)
        {
            char c=s[i];
            for(auto it=st.begin();it!=st.end();it++)
            {
                string temp=*it;
                if(i>=temp.size() || temp[i]!=s[i])
                {
                    st.erase(it);
                    // it--;
                }
            }
            vector<string>v;
            if(st.empty())
            v.push_back("0");
            else
            {
            for(auto x:st)
            v.push_back(x);
            }
            a.push_back(v);
        }
        return a;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends