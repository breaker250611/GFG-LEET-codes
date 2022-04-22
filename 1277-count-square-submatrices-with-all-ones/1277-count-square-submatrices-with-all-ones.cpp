class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]==1){
                    if(i==0||j==0) count +=matrix[i][j];
                else{
                    matrix[i][j] = max(matrix[i][j],min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]})+matrix[i][j]);
                    count += matrix[i][j];
                }
                }
            }
        }
        // for(auto &it:matrix){
        //     for(auto &x:it) cout<<x<<" ";
        //     cout<<endl;
        // }
        return count;
    }
};