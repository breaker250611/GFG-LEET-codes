class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = matrix[0].size()-1;j>=0;j--){
                if(i==matrix.size()-1 or j == matrix[0].size()-1){
                    count +=matrix[i][j];
                }
                else if(matrix[i][j]!=0){
                    matrix[i][j] = matrix[i][j] + min({matrix[i+1][j] , matrix[i][j+1],matrix[i+1][j+1]});
                    count +=matrix[i][j];
                }
            }
        }
        // for(auto &it:matrix){
        //     for(auto &i:it)cout<<i<<" ";
        // cout<<endl;
        // }
            return count;
    }
};