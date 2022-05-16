class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& times, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<times.size();i++){
        // cout<<"check";
            int ui = times[i][0];
            int vi = times[i][1];
            int wi = times[i][2];
            adj[ui].push_back({vi,wi});
        }
        vector<vector<int>>dist(101,vector<int>(101,INT_MAX));
        vector<int> parent(n,-1);
        dist[src][k+1] = 0;

        using pii = pair<int,pair<int, int>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0,{src,k+1}});
        while(!q.empty()){
            int v = q.top().second.first;
            int k = q.top().second.second;
            int d_v = q.top().first;
            q.pop();
            if(d_v>dist[v][k]) continue;
                // dist[v][k] = d_v;
            cout<<"d_v= "<<d_v<<endl;
            cout<<"dist[v][k]"<<dist[v][k]<<endl;
             for(auto edge:adj[v]){
                int to = edge.first;
                int len = edge.second;
                 if(k==0) continue;
            

                if(d_v+ len <dist[to][k-1]){
                    dist[to][k-1] = d_v + len;
                    q.push({dist[to][k-1],{to,k-1}});
                }
            }
        
        }
        int ans = INT_MAX;
        for(int i = 0;i<=100;i++){
            if(ans>dist[dst][i]){
                ans = dist[dst][i];
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};