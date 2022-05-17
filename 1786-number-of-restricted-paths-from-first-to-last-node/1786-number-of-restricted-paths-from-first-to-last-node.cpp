using ll = long long int;
class Solution {
public:
    ll mod = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
     
        vector<vector<int>> adj[n+1];
        
        for (auto x : edges){
            adj[x[0]].push_back({x[1] , x[2]});
            adj[x[1]].push_back({x[0] , x[2]});
        }
        
        vector<ll> dis(n+1 , (ll)1e15);
        using ti = tuple<int , int>;
        
        priority_queue<ti , vector<ti> , greater<ti>> pq;
        pq.push({0 , n});
        dis[n] = 0;
        while (!pq.empty()){
            auto [d_src , src] = pq.top();
            pq.pop();
            
            if (d_src > dis[src]) continue;
            
            for (auto x : adj[src]){
                ll to = x[0];
                ll len = x[1];
                if (dis[to] > d_src + len ){
                    dis[to] = d_src+len;
                    pq.push({dis[to] , to});
                }
            } 
        }  

        vector<ll> dp(n+1 , 0);
        vector<ll> vis(n+1 , 0);
        priority_queue<ti , vector<ti> , greater<ti>> q;
        q.push({ 0 , n});
        dp[n] = 1;
        while (!q.empty()){
            auto [d_u , u] = q.top();
            q.pop();
            for (auto x : adj[u]){ 
                if (dis[x[0]] > d_u){
                    dp[x[0]] = (dp[x[0]] + dp[u])%mod;
                    if (!vis[x[0]]){
                        q.push({dis[x[0]]  , x[0]});   
                        vis[x[0]] = true;
                    }
                }
            }
        }
        return dp[1];            
    }
};