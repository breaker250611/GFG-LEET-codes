class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        
        karna(ans,s,0,{});
        return ans;
    }
    bool palindrome(string s){
        int lo = 0;
        int hi = s.size()-1;
        
        while(lo<=hi){
            if(s[lo]==s[hi]){
                lo++;
                hi--;
            }
            else return false;
        }
        return true;
    }
    void karna(vector<vector<string>>&ans,string s,int start,vector<string>psf
){
        if(start==s.size()){
            ans.push_back(psf);
            return;
        }
        
        for(int i = start;i<s.size();i++){
            string sbr = s.substr(start,i-start+1);
            if(palindrome(sbr)){
                psf.push_back(sbr);
                karna(ans,s,i+1,psf);
                psf.pop_back();
            }
        }
    }
};