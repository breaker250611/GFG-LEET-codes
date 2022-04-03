class Solution {
public:
   vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        vector<int>res;
        for(auto temp:edges)
        {  ans[temp[1]]++;
        }
        for(int i=0;i<n;i++)
        {
           if(ans[i]==0) res.push_back(i);
        }
        return res;
    }
};