class Solution {
public:
//https://leetcode.com/problems/largest-1-bordered-square/discuss/345265/c%2B%2B-beats-100-(both-time-and-memory)-concise-with-algorithm-and-image
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>>dph(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dpv(grid.size(),vector<int>(grid[0].size(),0));
        
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                
                if(grid[i][j]){
                    
                    dph[i][j] = grid[i][j];
                    if(j>0){
                        dph[i][j] +=dph[i][j-1];
                    }
                    dpv[i][j] = grid[i][j];
                    if(i>0){
                        dpv[i][j] += dpv[i-1][j];
                    }
                    
                }
            }
        }
        int ans = 0;
        
        for(int i = grid.size()-1;i>=0;i--){
            for(int j = grid[0].size()-1;j>=0;j--){
                int temp = min(dph[i][j],dpv[i][j]);
                
                while(temp>ans){
                    if(dph[i-temp+1][j]>=temp and dpv[i][j-temp+1]>=temp){
                        ans = temp;
                     break;   
                    }
                    temp--;
                }
            }
        }
        
        
        return ans*ans;
    }
};