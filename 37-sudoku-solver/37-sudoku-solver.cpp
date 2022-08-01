class Solution {
    public:
    vector<vector<char>> board, ans;
    int ROW;
    int COL;

    void print() {
        for (int i= 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout << board[i][j] << ' ';
            } cout << '\n';
        } cout << "\n\n";
    } 
    bool present(int row, int col, int value) {
        for (int i = 0; i < COL; i++) {
            if (board[row][i] - '0' == value) {
                return true;
            }
        }

        for (int i = 0; i < ROW; i++) {
            if (board[i][col] - '0' == value) {
                return true;
            }
        }
        int chotai = row/3*3;
        int chotaj = col/3*3;
        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3 ; j++) {
                if (board[chotai+i][chotaj+j] - '0' == value) {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(int row, int col) {
        if (col >= COL) {
            col = 0; 
            row += 1; 
        }

        if (row == ROW) {
            ans = board;
            return;
        }


        if (board[row][col] != '.') {
            dfs(row, col + 1);
            return;
        } else {
            for (int value = 1; value <= 9; value ++) {
                if (!present(row, col, value)) {
                    // print();

                    board[row][col] = value + '0';
                    dfs(row, col + 1);
                    board[row][col] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        this->ROW = board.size();
        this->COL = board[0].size();
        dfs(0, 0);
        board = ans;
    }
};