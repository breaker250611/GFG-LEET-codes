class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1;i<triangle.size();i++){
            int prev = triangle[i-1].size();
            for(int j = 0;j<triangle[i].size();j++){
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j==prev){
                    triangle[i][j] +=  triangle[i-1][j-1];
                }
                else{
                    triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i =0;i<triangle[n-1].size();i++){
            if(triangle[n-1][i]<ans) ans = triangle[n-1][i]; 
        }
        return ans;
    }
};