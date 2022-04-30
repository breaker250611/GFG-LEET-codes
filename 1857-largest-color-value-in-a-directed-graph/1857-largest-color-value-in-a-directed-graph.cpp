class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        
        int n = color.size();
        vector<int> adj[n];
        vector<vector<int>> dp(n , vector<int>(27 , 0));
        vector<int> indeg(n , 0);
        
        for (auto x : edges){
            adj[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        queue<int> q;
        for (int i = 0 ; i<n ; i++){
            dp[i][color[i]-'a'] = 1;
            if (indeg[i] == 0){
                q.push(i);
                dp[i][color[i]-'a'] = 1;
            }
        }
        int ans = 1;
        int count = 0;
        while (!q.empty()){
            auto u = q.front(); q.pop();
            count += 1;   
            for (auto x : adj[u]){
                for (int i = 0 ; i<= 26 ; i++){
                    if ((color[x]-'a') == i){
                        dp[x][i] = max((1 + dp[u][i]) , dp[x][i]);
                    }
                    else{
                        dp[x][i] = max(dp[x][i] , dp[u][i]);
                    }
                    ans = max(ans , dp[x][i]);
                }
                indeg[x]--;
                if (indeg[x] == 0){
                    q.push(x);
                }
            }
        } 
        // for (int i = 0 ; i<n ; i++){
        //     for (int j = 0 ; j<= 26 ; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (count == n) return ans;
        return -1;
    }
};