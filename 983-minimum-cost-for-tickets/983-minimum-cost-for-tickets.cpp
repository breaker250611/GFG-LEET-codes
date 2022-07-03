class Solution {
public:
    vector<int>dayd={1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>st(days.begin(),days.end());
        vector<int>dp(days.back()+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<dp.size();i++){
            if(st.find(i)==st.end()) {dp[i] = dp[i-1];
                                     continue;}
            int day = i ;
            for(int k = 0;k<3;k++){
                if(max(day-dayd[k],0)>=0&&dp[max(day-dayd[k],0)]!=INT_MAX){
                    dp[day] = min(dp[day],dp[max(day-dayd[k],0)]+costs[k]);
                }
            }
        }
        // for(auto &it:dp)cout<<" "<<it<<" ";
        // cout<<endl;
        return dp[days.back()];
    }
};