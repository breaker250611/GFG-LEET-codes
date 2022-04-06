class Solution {
public:
    vector<string>vp = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)return ans;
        huakya(digits,ans,0,"");
        return ans;
    }
    void huakya(string digits,vector<string >&ans,int i,string psf){
            if(i==digits.size()){
            ans.push_back(psf);
            return;
        }
        string temp = vp[digits[i]-'0'];
        for(int j = 0;j<temp.size();j++){
            huakya(digits,ans,i+1,psf+temp[j]);
        }
    }
    
};