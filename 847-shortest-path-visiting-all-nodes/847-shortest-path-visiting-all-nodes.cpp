class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<vector<bool>>visited(n,vector<bool>(1<<n,false));
        queue<pair<int,int>>Q;

        int node;
        int mask;        
        
        
        for(int i=0;i<n;i++)
        {
            node = i;
            mask = 1<<i;
            Q.push({node,mask});
            visited[node][mask] = true;
        }
        
        int dist = -1;
        int finalVal = (1<<n)-1;
        int nextMask;
        while(!Q.empty())
        {
            int s = Q.size();
            dist++;
            while(s--)
            {
                node = Q.front().first;
                mask = Q.front().second;
                Q.pop();
    
                if(mask == finalVal)return dist;
          
                for(int &adj: graph[node])
                {
       
                    nextMask = mask | 1<<adj;
                    
    
                    if(visited[adj][nextMask])continue;
  
                    visited[adj][nextMask] = true;
                    Q.push({adj,nextMask});
                }
            }
        }
        
        return dist;
    }
};