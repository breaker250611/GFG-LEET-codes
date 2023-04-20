class Solution {
public:
    vector<vector<char>>ans;
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        board = ans;
        
    }
    
    
    void solve(vector<vector<char>>&board , int i , int j){
        
        // base 
        if(i==9){
            ans = board;
            return;
        }
        
        
        
        // calls
        
        int nayai = i;
        int nayaj= j;
        if(j==board[0].size()-1){
            nayaj = 0;
            nayai = nayai+1;
        }
        else{
            // nayai = i;
            nayaj = nayaj+1;
        }
        
        
        if(board[i][j]!='.'){
            solve(board,nayai,nayaj);
        }
        else{
            for(int val = 1;val<=9;val++){
                if(check(board,i,j,val)){
                    board[i][j] = val+'0';
                    solve(board,nayai,nayaj);
                    board[i][j]='.';
                }
            }
        }
        
    }
    bool check(vector<vector<char>>&board,int i ,int j, int val){
        
        // for row checking
        
        for(int y = 0;y<9;y++){
            if(board[i][y]==val+'0'){
                return false;
            }
        }
        // for column
        
        for(int x = 0;x<9;x++){
            if(board[x][j]==val+'0'){
                return false;
            }
        }
        
        // 3*3 wale box mia 
        
        int starti = i/3*3;
        int startj = j/3*3;
        
        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++){
                if(board[starti+x][startj+y]==val+'0'){
                    return false;
                }
            }
        }
        return true;
    }
};