class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>>G(points.size());
        for(int i = 0;i<points.size();i++){
            for(int j = i+1;j<points.size();j++){
                if(i==j) continue;
                int dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                G[i].push_back({j,dis});
                G[j].push_back({i,dis});
            }
        }
        int ans = 0,cur = 0;
        vector<int>dist(points.size(),INT_MAX),seen(points.size());
        int N = points.size();
         for (int i = 0; i < N - 1; ++i) {
        seen[cur] = 1; 
        for (auto &[v, w] : G[cur]) {
            if (seen[v]) continue; 
            dist[v] = min(dist[v], w);
        }
        cur = min_element(begin(dist), end(dist)) - begin(dist); 
        ans += dist[cur];
        dist[cur] = INT_MAX;
    }
    return ans;
    }
};