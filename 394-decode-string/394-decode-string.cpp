class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.size() ;i++){
            if (s[i] != ']'){
                st.push(s[i]);
            }
            else {
                string ok;
                while (!st.empty() and st.top() != '['){
                    ok += st.top();
                    st.pop();
                }
                st.pop();
                string no;
                while (!st.empty() and st.top() >= '0' and st.top() <= '9'){
                    no += st.top();
                    st.pop();
                }
                reverse(no.begin() , no.end());
                int it = stoi(no);
                reverse(ok.begin(), ok.end());
                for (int i = 1 ; i <= it ; i++){
                    for (auto x : ok){
                       st.push(x);
                    }
                }
            }
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};