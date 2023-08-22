class Solution {
public:
    
    string convertToTitle(int columnNumber) {
        map<char,int>mp;
        int i = 0;
        for(char ch = 'A' ;ch<='Z';ch++){
            mp[i] = ch;
            i++;
        }
        string ans = "";
        while(columnNumber){
        columnNumber--;
           int divi = columnNumber%26;
            char ch = mp[divi];
            ans = ch+ans;
            
            columnNumber = columnNumber/26;
        }
        
        
        // ans = char(mp[columnNumber]) + ans;
        return ans;
    }
};