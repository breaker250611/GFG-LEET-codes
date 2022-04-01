class Solution {
    
    bool dfs(int node,vector<int> &marks,vector<int> &vis,vector<int> &cycle,vector<vector<int>> &adj){
        marks[node] = 1;
        if(!vis[node]){
            vis[node] = 1;
            for(auto it: adj[node]){
                if(vis[it]==0 && dfs(it,marks,vis,cycle,adj)){
                    return cycle[node] = true;
                }
                else if(marks[it]) return cycle[node] = true;
            }
        }
        marks[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> mark(n,0),vis(n,0),cycle(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,mark,vis,cycle,graph);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(cycle[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};