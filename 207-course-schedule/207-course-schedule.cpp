class Solution {
public:
     bool ans;
    vector<int> color;
     void dfs (vector<int> adj[] , int node){
         color[node] = 1;
         for (auto x : adj[node]){
             if (color[x] == 0){
                 dfs(adj ,x);
             }
             else if (color[x] == 1){
                 ans = false;
                 return;
             }
         }
         color[node] = 2;
     }

    bool canFinish(int numCourses, vector<vector<int>>& pq) {
        
        vector<int> indeg(numCourses+1 , 0);
        vector<int> adj[numCourses+1];
        color.resize(numCourses+1 , 0);
        for (int i = 0 ; i<pq.size() ; i++){
            adj[pq[i][0]].push_back(pq[i][1]);
        }
        ans = 1;
        for (int i = 0 ; i<numCourses ; i++){
            if (color[i] == 0){
                dfs( adj , i);
            }
        }
        return ans;   
    }
};