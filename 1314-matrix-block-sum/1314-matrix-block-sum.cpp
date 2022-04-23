class Solution {
    public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = prefix[i][j - 1] 
                    + prefix[i - 1][j] 
                    - prefix[i - 1][j - 1] 
                    + mat[i - 1][j - 1];
            }
        }

        
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                int curr_i = min(i + k, n); 
                int curr_j = min(j + k, m);
                int prev_i = max(i - k - 1, 0); 
                int prev_j = max(j - k - 1, 0);

                ans[i - 1][j - 1] = prefix[curr_i][curr_j] 
                    - prefix[curr_i][prev_j] 
                    - prefix[prev_i][curr_j] 
                    + prefix[prev_i][prev_j];
            }
        }
        return ans;
    }
};