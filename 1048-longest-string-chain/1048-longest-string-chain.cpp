class Solution {
public:
   
    bool check(string &str1,string &str2){
        
        int i = 0;
        int j = 0;
            while(i<str1.size()&&j<str2.size()){
                if(str1[i]==str2[j]) {
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
        if(abs((int)str1.size()-(int)str2.size())==1 &&i>=str1.size()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const std::string& first,const std:: string&second){
            return first.size()<second.size();
        });
        vector<int>dp(words.size()+1,1);
        for(int i = 0;i<words.size();i++){
            for(int j = 0;j<i;j++){
                if(check(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        for(auto &it:dp)cout<<it<<" ";
        // cout<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};