class Solution {
public:
    vector<int>dp;
    int call(string s,int ind,vector<string>& words){
        if(ind>=s.size())return 0;
        int &ans = dp[ind];
        if(ans!= -1)return ans;
        int op1  = call(s,ind+1,words)+1;
        
        int op2 = INT_MAX;
        for(auto&word:words){
            string temp = s.substr(ind,word.size());
            if(temp==word){
                int check = call(s,ind+word.size(),words);
                op2 = min(check,op2);
            }
        }
        
        
         ans = min(op1,op2);
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
        dp.resize(51,-1);
        int ans = call(s,0,dictionary);
        return ans;
    }
};