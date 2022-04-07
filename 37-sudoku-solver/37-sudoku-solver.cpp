class Solution {
public:
    vector<vector<char>>ans;
    void solveSudoku(vector<vector<char>>& board) {        
        solve(board,0,0);
        board = ans;
    }
    void solve(vector<vector<char>>&board,int i,int j){
        if(i==board.size()) {
            ans = board;
            return;
        }
        int nayai ;
        int nayaj ;
        if(j==board[0].size()-1){
            nayai = i+1;
            nayaj = 0;
        }
        else{
            nayai = i;
            nayaj = j+1;
        }
        
        if(board.at(i).at(j)!='.') solve(board,nayai,nayaj);
        else{
            for(char no = 1;no<=9;no++){
                if(sahihai(board,i,j,no)){
                    board[i][j]=no+'0';
                    solve(board,nayai,nayaj);
                    board[i][j]='.';
                }
            }
        }
    }
    bool sahihai(vector<vector<char>>&board,int i,int j,int num){
        for(int y = 0;y<board[0].size();y++){
            if(board[i][y]-'0'==(num)) return false;
        }
        for(int y = 0;y<board.size();y++){
            if(board[y][j]-'0'==(num)) return false;
        }

        int chotai = i/3*3;
        int chotaj  = j/3*3;
        for(int a = 0;a<3;a++){
            for(int b = 0;b<3;b++){
                if(board[a+chotai][b+chotaj]==(num+'0')) return false;
            }
        }
        return true;
    }
};