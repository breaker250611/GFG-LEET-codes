class Solution {
public:
    bool pali(string s){
        int i = 0;
        int hi = s.size()-1;
        while(i<hi){
            if(s[i++]==s[hi--]) continue;
            return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
         string temp = "";
        
        
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(ch>='A' and ch<='Z'){
                ch += 32;
                temp +=ch;
            }
            else if(ch>='a' and ch<='z') temp += ch;
            else if(ch>='0' and ch<='9') temp += ch;
        }
        return pali(temp);
    }
};