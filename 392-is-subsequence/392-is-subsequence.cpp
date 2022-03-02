class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char>st;
        for(auto ch:s) st.push(ch);
        for(auto ch:t){
            if(st.front()==ch) st.pop();
        }
        if(st.size()==0) return true;
        else return false;
    }
};