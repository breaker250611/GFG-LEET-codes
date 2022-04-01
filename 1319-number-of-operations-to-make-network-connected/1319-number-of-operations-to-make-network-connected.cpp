class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &visi)
    {
        visi[node] = 1;
        for(auto i: adj[node]){
            if(!visi[i]){
                dfs(i, adj, visi);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
    
        if(edges.size() < n-1) return -1;
        vector<int> adj[n];
        for(auto i: edges){ 
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int comp = 0;
        vector<int> visi(n, 0);
        for(int i=0; i<n; i++){
            if(!visi[i]){
                dfs(i, adj, visi);
                comp++; 
            }
        }
        return comp-1;
    }
};