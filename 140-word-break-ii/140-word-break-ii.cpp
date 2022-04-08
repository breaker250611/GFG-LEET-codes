class Solution {
public:
    map<string,int>mp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        for(int i = 0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        vector<string>ans;
        karbhaicall(s,ans,"",0);
        return ans;
    }
    
    void karbhaicall(string s,vector<string>&ans,string psf,int i){
        
        if(i==s.size()){
            psf.pop_back();
            ans.push_back(psf);
        }
        
        for(int j = i;j<s.size();j++){
            string abhi = s.substr(i,j-i+1);
            if(mp.find(abhi)!=mp.end()){
                karbhaicall(s,ans,psf+abhi+" ",j+1);
            }
        }
    }
};