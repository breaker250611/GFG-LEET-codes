class Solution {
public:
     vector<int>ans;
    vector<int> color;
    bool check = true;
     void dfs (vector<int> adj[] , int node){
         color[node] = 1;
         for (auto x : adj[node]){
             if (color[x] == 0){
                 dfs(adj ,x);
             }
             else if (color[x] == 1){
                 ans= {};
                 check = false;
                 return ;
                 // exit(0);
             }
         }
         ans.push_back(node);
         color[node] = 2;
     }

    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pq) {
        vector<int> indeg(numCourses+1 , 0);
        vector<int> adj[numCourses+1];
        color.resize(numCourses+1 , 0);
        ans.clear();
        check = true;
        for (int i = 0 ; i<pq.size() ; i++){
            adj[pq[i][0]].push_back(pq[i][1]);
        }
        // ans = 1;
        for (int i = 0 ; i<numCourses ; i++){
            if (color[i] == 0){
                dfs( adj , i);
            }
        }
       if(check) return ans;
        return {};
    }
};