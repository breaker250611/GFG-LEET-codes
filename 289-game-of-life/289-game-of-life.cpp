int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};

class Solution {
public:
    
    void gameOfLife(vector<vector<int>>& board) {
       auto dp = board;
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                int count = 0;
                for(int t = 0;t<8;t++){
                    int rr = dr[t]+i;
                    int cc =dc[t]+j;
                    if(rr<0||cc<0||rr>=board.size()||cc>=board[0].size()) continue;
                    
                    if(board[rr][cc]==1) count++;
                }
                if(board[i][j]==1){
                    if(count<2) dp[i][j] = 0;
                    if(count==2||count==3) dp[i][j] = 1;
                    if(count>3) dp[i][j] = 0;
                    
                }
                else{
                    if(count==3) dp[i][j] = 1;
                }

            }
        }
        board = dp;
    }
};