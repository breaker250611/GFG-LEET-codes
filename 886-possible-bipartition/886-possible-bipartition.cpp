class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n+1);
        vector<int> pos(n+1,0);
        vector<bool> visited(n+1, false);
        bool ans = true;
        
        for(int i=0; i<dislikes.size(); i++){
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1; i<=n; i++){
            ans = ans && dfs(i, g, pos, visited);
        }
        
        return ans;
    }
    
    bool dfs(int now, vector<vector<int>>& g, vector<int>& pos, vector<bool>& visited){
        if(visited[now]) return true;
        visited[now] = true;
        
        if(pos[now] == 0){
            pos[now] = 1;
            
            for(int gasuka : g[now]){
                pos[gasuka] = 2;
            }
            
            bool res=true;
            for(int gasuka : g[now]){
                res = res && dfs(gasuka, g, pos, visited);
            }
            return res;
        }
        
        if(pos[now] == 1){
            for(int gasuka : g[now]){
                if(pos[gasuka] == 1) return false;
            }
            
            for(int gasuka : g[now]){
                pos[gasuka] = 2;
            }
            
            bool res=true;
            for(int gasuka : g[now]){
                res = res && dfs(gasuka, g, pos, visited);
            }
            return res;
        }
        
        if(pos[now] == 2){
            for(int gasuka : g[now]){
                if(pos[gasuka] == 2) return false;
            }
            
            for(int gasuka : g[now]){
                pos[gasuka] = 1;
            }
            
            bool res=true;
            for(int gasuka : g[now]){
                res = res && dfs(gasuka, g, pos, visited);
            }
            return res;
        }
        return false;
    }
};