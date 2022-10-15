//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int ans = -1;
        queue<pair<int,int>>q;
        if(grid[source.first][source.second]==0 or grid[destination.first][destination.second]==0){
            return ans;
        }
        q.push(source);
        grid[source.first][source.second] = 0;
        int level = 0;
        while(q.size()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                if(x==destination.first and y == destination.second){
                    return level;
                }
                for(int i = 0;i<4;i++){
                    int nx = x+dr[i];
                    int ny = y+dc[i];
                    if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]!=0){
                    grid[nx][ny] = 0;
                    q.push({nx,ny});                        
                    }
                }         
                
            }
            level++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends