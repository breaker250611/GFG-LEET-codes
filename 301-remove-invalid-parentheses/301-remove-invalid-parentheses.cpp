class Solution {
public:
    set<string> ans;
    vector<string>fi;
    string temp;
    int checkmin (string s){
        stack<char> st;
        for (auto x : s){
            //cout << x << " ";
            if (x != '(' and x != ')') {}
            else if(x == '('){st.push(x);}
            else {
                if (st.empty() or st.top() == ')'){st.push(x);}
                else st.pop();
            }
        }
        // while (!st.empty()){
        //     cout <<st.top() << endl;
        //     st.pop();
        // }
        return st.size();
    }
    
    void func(string &s , int i , int sz , int open , int close){
        // checking vala part rhe gaya //
                
       
            if (open == close and s.size()-sz == temp.size()){
               fi.push_back(temp);
            
            // return;
        }
        if (close > open){
            return;
        }
        else {
            for(int j = i;j<s.size();j++){
                if(s[j]!='(' and s[j]!=')'){
                    temp.push_back(s[j]);
                    func(s,j+1,sz,open,close);
                    temp.pop_back();
                }
                else{
                    if(j>i and s[j]==s[j-1])continue;
                    temp.push_back(s[j]);
            func(s , j+1 , sz , open + (s[j] == '(' ? 1 : 0) , close + (s[j] == ')' ? 1 : 0));
            temp.pop_back();
                }
            }
        }
        
//  
    }
    
    vector<string> removeInvalidParentheses(string s) {
      int val = checkmin(s); 
        temp.clear();
        fi.clear();
     // cout << val << endl;
      func(s , 0 , val , 0, 0);  
    
       // for (auto x : ans ){fi.push_back(x);}
       // return fi;
        // if(fi.size()==0)fi.push_back("");
        return fi;
    }
};