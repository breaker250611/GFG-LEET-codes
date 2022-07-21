// MR. Babu help me .

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        
        st.push(num[0]);
        
        for(int i = 1;i<num.size();i++){
            char ch = num[i];
            
            while(st.size()>0 and (k>0 and num[i]<st.top())){
                st.pop();
                k--;
            }
            st.push(ch);
            if(st.size()==1 &&  num[i]=='0' ) st.pop();
        }
        while(k>0 and st.size()>0){
            k--;
            st.pop();
        }
        string res = "";
        while(st.size()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
    return res == ""?"0":res;
    }
};