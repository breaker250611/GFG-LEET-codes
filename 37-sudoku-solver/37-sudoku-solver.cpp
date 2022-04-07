class Solution {
    public:
    int n, m;
    vector<vector<char>> board, ans;

    void fun(int i, int j,vector<vector<char>>&board) {
        cout << i << ' ' << j << '\n';
        if (i >= n) {
           ans=board; 
            return;
        }

        int r = -1;
        int c = -1;
        if(j==9) return;
        if (j == n-1) {
            r = i + 1;
            c = 0;
        }
        else {
            r = i;
            c = j + 1;
        }

        cout << " r : " << r << " , c : " << c << '\n';
        if(board[i][j]!='.') fun(r,c,board);
        else  {
            for (int val = 1; val <= 9; val ++) {
                if (check(i, j, val,board)) {
                    board[i][j] = '0' + val;
                    fun(r, c,board);
                    board[i][j] = '.';
                }
            }
        }
      
    }

    bool check(int r, int c, int num,vector<vector<char>>&board) {
        for (int y = 0; y < board[0].size(); y++) {
            if (board[r][y] - '0' == (num))
                return false;
        }
        for (int y = 0; y < board.size(); y++) {
            if (board[y][c] - '0' == (num))
                return false;
        }

        int rr = r / 3 * 3;
        int cc = c / 3 * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + rr][j + cc] == (num + '0'))
                    return false;
            }
        }
        return true;


    }
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();


        fun(0, 0,board);
        board = ans;
    }
};