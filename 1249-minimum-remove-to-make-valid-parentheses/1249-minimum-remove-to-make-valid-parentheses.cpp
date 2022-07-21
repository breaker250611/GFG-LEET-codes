class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        for (int i = 0 ;i < s.size() ; i++){
                if (s[i] == '('){
                    st.push(i);
                }
                else if (s[i] == ')'){
                    if (!st.empty() and s[st.top()] == '('){
                        st.pop();
                    }
                    else {
                        st.push(i);
                    }
                }
        }
        
        string res;
        for (int i = s.size()-1 ; i >= 0 ; i--){
            if (!st.empty() and i == st.top()){
                st.pop();
            }
            else 
                res += s[i];
        }
        
        reverse(res.begin() , res.end());
        return res;
        
    }
};