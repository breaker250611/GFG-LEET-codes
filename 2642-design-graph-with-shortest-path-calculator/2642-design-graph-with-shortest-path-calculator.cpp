class Graph {
public:
    vector<pair<int , int>> adj[105];
    Graph(int n, vector<vector<int>>& edges) {
        for (auto x : edges)
        {
            adj[x[0]].push_back({x[1] , x[2]});
        }    
    }
    
    
    int dk(int x , int y){
        
        vector<int> dis(105 , INT_MAX);
        dis[x] = 0;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        pq.push({0 , x});
        while(!pq.empty()){
        
            auto D = pq.top().first;
            auto node  = pq.top().second;
            pq.pop();
            // if (D > dis[node]) continue;
            
            for (auto x : adj[node]){
                
                int u = x.first;
                int w = x.second;
                
                if (dis[u] > dis[node] + w)
                {
                    dis[u] = dis[node] + w;
                    pq.push({dis[u] , u});
                }                
            }
        }
        
       return dis[y] == INT_MAX ? -1 : dis[y]; 
    }
    
    
    
    
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1] , edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dk(node1 , node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */