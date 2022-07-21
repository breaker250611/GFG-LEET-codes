class Solution {
public:
    string simplifyPath(string path) {
         stringstream in(path);
        string s; 
        vector<string> pth;

        while (getline(in, s, '/')) {
            if (!s.empty())
                pth.push_back(s);
        }
        stack<string>st;
        
        for(int i = 0;i<pth.size();i++){
            string temp = pth[i];
            if(st.size()>0 and temp=="..") st.pop();
            else if(temp != "" and temp != "." and temp != "..") st.push(temp);
        }
        
        
        if(st.size()==0) return "/";
        else {
            string res = "";
            while(st.size()){
                string temp = st.top();
                st.pop();
                temp = "/" + temp;
                res = temp + res;
            }
            return res;
        }
        return "";
    }
};