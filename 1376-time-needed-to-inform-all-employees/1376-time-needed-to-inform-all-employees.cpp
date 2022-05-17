class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int par = -1;
        using ti = tuple<int , int>;
        vector<ti> adj[n+1];
        for (int i = 0 ; i< n ; i++){
            if (manager[i] != -1)
                adj[manager[i]].push_back({ i , informTime[i]});
            else 
                par = i;
        }
     
        vector<int> dis(n  , INT_MAX);
        dis[par] = informTime[par];
        priority_queue<ti , vector<ti> , greater<ti>> pq;
        pq.push({informTime[par] , par});
        while(!pq.empty()){
            auto [du  , u] = pq.top();
            pq.pop();
            if (du > dis[u]) continue;
            
            for (auto [to , len] : adj[u]){
                if ( du + len < dis[to]){
                    dis[to] = du+len;
                    pq.push({dis[to] , to });
                }
            }
        }
        return *max_element(dis.begin() , dis.end());
    }
};