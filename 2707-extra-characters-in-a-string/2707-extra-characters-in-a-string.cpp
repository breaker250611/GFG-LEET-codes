class Solution {
public:
    vector<vector<int>>dp;
    map<string,int>mp;
    int call(string s,int ind,string sofar){
        if(ind>=s.size() and sofar =="")return 0;
        else if(ind>=s.size()){
            return 55;
        }
        int &ans = dp[ind][sofar.size()];
        if(ans!= -1)return ans;
        int op1  = call(s,ind+1,sofar)+1;
        
        int op2 = INT_MAX;
        sofar += s[ind];
        // for(auto&word:words){
        //     string temp = s.substr(ind,word.size());
        //     if(temp==word){
        //         int check = call(s,ind+word.size(),words);
        //         op2 = min(check,op2);
        //     }
        // }
        int op3 = INT_MAX;
        if(mp.find(sofar)!=mp.end()){
        // cout<<sofar<<endl;
            op2 = call(s,ind+1,"");
            // cout<<op2<<endl;
        }
        
             op3 = call(s,ind+1,sofar);
        // if(op3==0)op3 = 52;
        
        
        
      
         ans = min({op1,op2,op3});
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto&it:dictionary)mp[it]++;
        dp.resize(51,vector<int>(51,-1));
        int ans = call(s,0,"");
        return ans;
    }
};