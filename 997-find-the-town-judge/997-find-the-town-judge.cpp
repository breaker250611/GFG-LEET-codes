class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n > 1)
            return -1;
        unordered_map<int, unordered_set<int>> graph;
        int judge = -1; 
        for(auto& edge : trust)
            graph[edge[0]].insert(edge[1]);
        for(int i = 1; i <= n; i++){
            if(!graph.count(i)){
                judge = i;
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(i == judge) continue;
            if(!graph[i].count(judge))
                return -1;
        }
        return judge;
    }
};