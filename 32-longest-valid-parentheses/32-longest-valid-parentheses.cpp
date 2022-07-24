class Solution {
public:
    /*
    sabke index daalte jao and compare karte jao
    */
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxi = 0;
        
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(ch =='(') st.push(i);
            else {
                    st.pop();
                if(st.size()>0){
                    maxi = max(maxi,i-st.top());
                }else{
                    st.push(i);
                }
            }
        }
        return maxi;
    }
};