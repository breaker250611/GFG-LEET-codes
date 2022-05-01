class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        string first = "";
        stack<char>st1;
        string second = "";
        
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(ch=='#'&&!st.empty()){
                st.pop();
            }
            else if(ch!='#') st.push(ch);
        }
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            first +=ch;
        }
               cout<<first<<endl;
        for(int i = 0;i<t.size();i++){
            char ch = t[i];
            if(ch=='#'&&st1.empty()==false){
                st1.pop();
            }
            else if(ch!='#') st1.push(ch);
        }
        while(!st1.empty()){
            char ch = st1.top();
            st1.pop();
            second +=ch;
        }
                       cout<<second<<endl;

if(first==second) return true;
        return false;
    }
};