class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long int tot = 0;
        vector<bool>rows(n,1);
        vector<bool>col(n,1);
        
        int initialrow = n;
        int initialcol = n;
        
        
        for(int i = queries.size()-1;i>=0;i--){
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            
            
            if(type==0){
                if(rows[index]){
                    tot = tot+val*initialrow;
                    initialcol--;
                    rows[index] = 0;
                }
            }
            if(type==1){
                 if(col[index]){
                    tot = tot+val*initialcol;
                    initialrow--;
                    col[index] = 0;
                }
            }
        }
        return tot;
    }
};