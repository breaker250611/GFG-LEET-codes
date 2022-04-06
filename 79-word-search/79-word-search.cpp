class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    lagadi(board,word,i,j,0,ans);
                    if(ans) return true;
                    else continue;
                }
            }
        }
        return ans;
    }
    void  lagadi(vector<vector<char>>& board, string word,int i , int j,int k,bool &ans){
        if(i<0||j<0||k>=word.size()||i>=board.size()||j>=board[0].size()||board[i][j]!=word[k]) return;
       if(k==word.size()-1&&board[i][j]==word[k]){
           ans = true;
           return;
       }
        char temp = board[i][j];
        board[i][j] = 0;
        lagadi(board,word,i-1,j,k+1,ans);
        lagadi(board,word,i+1,j,k+1,ans);
        lagadi(board,word,i,j+1,k+1,ans);
        lagadi(board,word,i,j-1,k+1,ans);
        board[i][j] = temp;
        
    }
};