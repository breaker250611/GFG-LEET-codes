class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp;
        for(int i = 0;i<=query_row;i++){
            vector<double>sp(i +1,0);
            if(i==0){
                sp[0] = poured;   
            }
            else{
                for(int j = 0;j<sp.size();j++){
                    if(j==0){
                        double temp = dp[i-1][j]-1;
                        // cout<<temp<<endl;
                        if(temp>=0){
                            sp[j] += temp/2.0; 
                        }
                    }
                    else if(j==sp.size()-1){
                        double temp = dp[i-1][j-1]-1;
                        if(temp>=0){
                            sp[j] += temp/2.0;
                        }
                    }
                    else{
                        double temp1 = dp[i-1][j-1]-1;
                        double temp = dp[i-1][j]-1;
                         if(temp1>=0){
                            sp[j] += temp1/2.0; 
                        } 
                        if(temp>=0){
                            sp[j] += temp/2.0; 
                        }
                    }
                }
            }
            dp.push_back(sp);
        }
        // for(auto&it:dp){
        //     for(auto &i:it)cout<<i<<" ";
        //         cout<<endl;
        // }
        double ans = dp[query_row][query_glass];
        return ans = ans>1?1:ans;
    }
};