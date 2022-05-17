class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<double,int>>> adj(n);
        vector<double>dp(n,0.0);
        dp[start] = 1.0;
        for(int i = 0;i<edges.size();i++){
            double wt = succProb[i];
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }
         using pii = pair<double, int>;
    priority_queue<pii> q;
        q.push({1.0,start});
        while(!q.empty()){
            int v = q.top().second;
            double d_v = q.top().first;
            q.pop();
            if(d_v<dp[v]) continue;
            for(auto edge : adj[v]){
                int to = edge.second;
                double prob = edge.first;
                double temp = prob*dp[v];
                if(temp>dp[to]){
                    dp[to] = temp;
                    if(to!=end){
                        q.push({dp[to],to});
                    }
                }
                
            }
        }
        for(auto &it:dp)cout<<it<<" ";
        cout<<endl;
        return dp[end];
    }
};