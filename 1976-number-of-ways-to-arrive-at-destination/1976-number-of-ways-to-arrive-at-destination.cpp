class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        using ll = long long int;
        using tii = tuple<ll, ll>; 
        
        vector<vector<tii>> graph(n + 1);
        for (const auto& i: roads) {
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        vector<ll> saved_dist(n + 1, 1e14);
        vector<ll> ans(n + 1, 0);
        
        pq.push({0, 0});
        saved_dist[0] = 0;
        ans[0] = 1;
        
        while (!pq.empty()) {
            auto [updated_dist, u] = pq.top(); 
            pq.pop(); 
            
            if (saved_dist[u] < updated_dist) 
                continue;
            
            for (const auto& [to, dist_till_to]: graph[u]) {
                if (dist_till_to + saved_dist[u] < saved_dist[to]) {
                    saved_dist[to] = (dist_till_to + saved_dist[u]);
                    pq.push({saved_dist[to], to});
                    
                    ans[to] = (ans[u] % mod) % mod;
                }
                else if (dist_till_to + saved_dist[u] == saved_dist[to]) {
                    ans[to] = (ans[to] % mod + ans[u] % mod) % mod;
                }
            }
        }
        
        return ans[n - 1] % mod;
    }
};