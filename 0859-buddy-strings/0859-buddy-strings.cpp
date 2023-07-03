class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size())return false;
        
        string temp1 = s;
        string temp2 = goal;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        
        if(temp1 != temp2)return false;
        int cnt = 0;
        vector<int>dp(26,0);
        for(int i = 0;i<s.size();i++){
            if(s[i]!=goal[i]){
                cnt++;
            }
            
            dp[s[i]-'a']++;
        }
        
        
        if(cnt==2)return true;
        bool flag = false;
        for(auto &it:dp){
            if(it>1){flag = true;
                    break;}
        }
        
        if(s==goal and flag)return true;
        return false;
        
    }
};