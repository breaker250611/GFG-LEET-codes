class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<times.size();i++){
        // cout<<"check";
            int ui = times[i][0]-1;
            int vi = times[i][1]-1;
            int wi = times[i][2];
            adj[ui].push_back({vi,wi});
        }
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n,-1);
        dist[k-1] = 0;
        using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0,k-1});
        while(!q.empty()){
             int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
            if(d_v > dist[v] ){
                continue;
            }
            for(auto edge:adj[v]){
                int to = edge.first;
                int len = edge.second;
                if(dist[v] + len <dist[to]){
                    dist[to] = dist[v] +len;
                    parent[to ] = v;
                    q.push({dist[to],to});
                }
            }
        }
        int ans = *max_element(dist.begin(),dist.end());
        if(ans == INT_MAX) return -1;
        return ans;
    }
};