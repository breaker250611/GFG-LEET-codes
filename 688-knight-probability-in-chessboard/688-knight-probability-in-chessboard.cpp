class Solution {
public:
       vector<int> dr;
    vector<int> dc;
    int n ;
    vector<vector<vector<double>>>dp;
    double call(int row,int col,int k){
        if(k==0)
            return 1;
        double &res = dp[k][row][col];
        if(res !=-1)return res;
        res = 0;
        for(int i = 0;i<8;i++){
            int tr = row+dr[i];
            int tc = col +dc[i];
            if(tr<0 or tc<0 or tr>=n or tc>=n ) continue;
            res += (1/8.0)*call(tr,tc,k-1);
        }
        return res;
    }
    double knightProbability(int n, int k, int row, int column) {
        this -> n = n;
        dp.resize(k + 1, 
                    vector<vector<double>>(n + 1, 
                                           vector<double>(n + 1, -1)));
         dr = {-2, -1, 1, 2, 2, 1, -1, -2};
        dc = {-1, -2, -2, -1, 1, 2, 2, 1};
        return call(row,column,k);
        
    }
};