class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        vector<int> ok(n*n+1 , 0) , v(n*n+1 , 0);
        int idx = 0;
        int right = 1;
        for (int i = n-1 ; i >= 0 ; i--){
            if (right){
                    for (int j = 0 ; j<n ; j++){
                        ++idx;
                        // cout << idx << endl;
                        ok[idx] = board[i][j] == -1 ? idx : board[i][j];
                    }
                right = 0;
            }
            else{
                 for (int j = n-1 ; j >= 0 ; j--){
                        ++idx;
                        ok[idx] = board[i][j] == -1 ? idx : board[i][j];
                    }
                right = 1;
            }
        }
        v[1] = 1;
        for (auto x : ok){cout << x << " ";}
        queue<int> q;
        q.push(1);
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                int node = q.front(); q.pop();
                for (int i = 1 ; i<= 6 ; i++){
                    if (node+i > n*n) break;
                    if (v[ok[node+i]] == 0){
                        q.push(ok[node+i]);
                        v[ok[node+i]] = v[node]+1;
                    }
                }   
            }
        }
        // for (auto x : v)
        //     cout << x << " ";
        return v[n*n]-1;
    }
};