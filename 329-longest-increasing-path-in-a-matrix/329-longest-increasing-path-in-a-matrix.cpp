class Solution {
public:
    int dp[201][201];
    vector<vector<int>> matrix;
    int n , m;
    bool ok (int i , int j){
        if (i < 0 or j < 0 or i >= n or j >= m)return 0;
        return 1;
    }
    int dfs (int i , int j){
        if (dp[i][j] != -1)
            return dp[i][j];
         
        // cout << i << " " << j << endl;
        int op1 = 0 , op2 = 0,  op3 = 0 ,  op4 = 0;
        
        if (ok(i+1, j) and matrix[i+1][j] > matrix[i][j])
        op1 = dfs(i+1 , j);
        
          if (ok(i , j+1) and matrix[i][j+1] > matrix[i][j])
        op2 = dfs(i , j+1);
        
          if (ok(i-1 , j) and matrix[i-1][j] > matrix[i][j])
        op3 = dfs(i-1 , j);
        
          if (ok(i , j-1) and matrix[i][j-1] > matrix[i][j])
        op4 = dfs( i , j-1);
        
        return dp[i][j] = 1 + max({op1 , op2 , op3 , op4});
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
       // dp.resize(n , vector<int>(m , -1));
        n = matrix.size() , m = matrix[0].size();
       
        for (int i = 0 ; i<= n ; i++){
            for(int j = 0 ; j<= m ; j++){
                dp[i][j] = -1;
            }
        }
        for (int i = 0 ; i<n ; i++){
            for (int j = 0; j < m ; j++){
                if (dp[i][j] == -1){
                   // cout << "hi";
                    dfs(i , j);
                }
            }
        }
        int ans = 0;
        for (int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
              ans = max( ans ,  dp[i][j]);
            }
        }
        return ans;
    }
};