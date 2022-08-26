class Solution {
public:
    int ans = 0;
    vector<vector<int>> grid;
    void call(int i ,int j ,int sum){
            ans = max(ans,sum);
        if(i<0 or j<0 or j>=grid[0].size() or i>=grid.size() or (grid[i][j]==0)) return;
        int temp = grid[i][j];
        grid[i][j] = 0;
            // cout<<"check";
        call(i+1,j,temp+sum);
        call(i,j+1,temp+sum);
        call(i,j-1,temp+sum);
        call(i-1,j,temp+sum);
        grid[i][j] = temp;
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ans = 0;
        this->grid = grid;
        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    int temp = grid[i][j];
                    // grid[i][j] = 0;
                    call(i,j,0);
    
                    // grid[i][j] = temp;
                }
            }
        }
        
        return ans;
    }
};