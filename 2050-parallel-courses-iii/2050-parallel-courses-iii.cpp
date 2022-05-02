class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> adj[n+1];
        vector<int> indeg(n+1 , 0);
        vector<int> dp(n+1 , -1);
        queue<int> q;
        for (int i = 0 ; i<relations.size() ; i++){
            adj[relations[i][0]].push_back(relations[i][1]);
            indeg[relations[i][1]]++;
        }
        
        for (int i = 1 ; i<=n ; i++){
            if (indeg[i] == 0){
                q.push(i);
                dp[i] = time[i-1];
            }
        }
    
        while (!q.empty()){
            auto u = q.front(); q.pop();
            for (auto v : adj[u]){
                dp[v] = max(dp[v] , time[v-1]+dp[u]);
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }   
        }
        
        return *max_element(dp.begin() , dp.end());
    }
};