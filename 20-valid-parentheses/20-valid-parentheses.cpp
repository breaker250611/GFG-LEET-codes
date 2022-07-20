class Solution {
public:
    /*
    1 = (
    2 = {
    3 = [
    -ve for other
    */
    bool isValid(string s) {
        stack<int>st;
        unordered_map<char,int>mp = {{'(',1},{')',-1},{'[',2},{']',-2},{'{',3},{'}',-3}};
        
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            int br = mp[ch];
            if(st.size()==0 && br<0) return false;
            if(br>0){
                st.push(br);
            }
            else{
                br = -1*br;
                if(st.top()==br) st.pop();
                else return false;
            }
        }
        if(st.size()==0)return true;
        return false;
    }
};