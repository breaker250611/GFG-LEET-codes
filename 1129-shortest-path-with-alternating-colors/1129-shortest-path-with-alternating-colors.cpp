class Solution {
public:
    vector<int> adjRed[102];
    vector<int> adjBlue[102];
    bool visited[102][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for(auto edge:redEdges){
            adjRed[edge[0]].push_back(edge[1]);
        }
        for(auto edge:blueEdges){
            adjBlue[edge[0]].push_back(edge[1]);
        }
        vector<int> distance(n,INT_MAX);
        queue<pair<int,pair<int,int>>> Q;
        
        for(int v:adjRed[0]){
            Q.push({v,{1,0}});
        }
        for(int v:adjBlue[0]){
            Q.push({v,{1,1}});
        }
        distance[0] = 0;
        while(!Q.empty()){
            auto curr = Q.front();Q.pop();
            int node = curr.first;
            int dist = curr.second.first;
            int color = curr.second.second;
            visited[node][color] = true;
            distance[node] = min(distance[node],dist);
            
            //red
            if(color == 0){
                for(int v:adjBlue[node]){
                    if(!visited[v][1]){
                        Q.push({v,{dist+1,1}});
                    }
                }
            }
            //blue
            else if(color == 1){
                for(int v:adjRed[node]){
                    if(!visited[v][0]){
                        Q.push({v,{dist+1,0}});
                    }
                }
            }
        }
        for(int &x:distance){
            if(x==INT_MAX) x= -1;
        }
        
        return distance;
    }
};