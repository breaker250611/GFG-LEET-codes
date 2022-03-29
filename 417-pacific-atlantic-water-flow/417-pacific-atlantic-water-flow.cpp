class Solution {
public:
    vector<vector<bool>> a , b;
    void dfs(vector<vector<int>>&heights , int i , int j, vector<vector<bool>>&vis , int curr){
        
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || vis[i][j] || heights[i][j] < curr)
            return;
        
        vis[i][j] = true;
        dfs(heights , i+1 , j , vis , heights[i][j]);
        dfs(heights , i , j+1 , vis , heights[i][j]);
        dfs(heights , i-1 , j , vis , heights[i][j]);
        dfs(heights , i , j-1 , vis , heights[i][j]);
    }
    
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        a.resize(n , vector<bool>(m , false));
        b.resize(n , vector<bool>(m , false));
        
        for (int j = 0 ; j<m ; j++){
            if (!a[0][j]){
                dfs(heights , 0 , j , a , heights[0][j]);
            }
            if (!b[n-1][j]){
                dfs(heights , n-1 , j , b , heights[n-1][j]);
            }
        }
        
        for (int i = 0 ; i<n ; i++){
             if (!a[i][0]){
                dfs(heights , i , 0 , a , heights[i][0]);
            }
            if (!b[i][m-1]){
                dfs(heights , i , m-1 , b ,  heights[i][m-1]);
            }
        }
        vector<vector<int>> ans;
        for (int i = 0 ; i<n ; i++){
            for (int j =0 ; j<m; j++){
                if (a[i][j] and b[i][j]){
                    ans.push_back({i , j});
                }
            }
        }
        return ans;
    }
};