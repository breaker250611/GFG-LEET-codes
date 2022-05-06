int dr[] = {1,-1,0,0};
int dc[]= {0,0,-1,1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<int,int>>qu ;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                  qu.push({i,j});
                    // dist[i][j] = 0;
                }    
            }
        }
            while(!qu.empty()){
                pair<int,int>dp = qu.front();
                qu.pop();
                int x = dp.first;
                int y = dp.second;
                for(int k = 0;k<4;k++){
                    int nx = dr[k]+x;
                    int ny = dc[k]+y;
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(grid[nx][ny]==2||grid[nx][ny]==0) continue;
                    qu.push({nx,ny});
                    dist[nx][ny] = dist[x][y]+1;
                    grid[nx][ny] = 2;
                    }
                
            }
            int maxi = 0;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(grid[i][j]==1) return -1;
                    maxi = max(dist[i][j],maxi);
                }
            }
            return maxi;
        }
    
};