class Solution {
public:
    vector<string>ans;
    void call(int n ,int khula,int band , string str){
        if((khula+band)>2*n)return;
        if(khula==band and 2*n == (khula+band)){
            ans.push_back(str);
            return;
        }
        if(khula<band)return;
        
        call(n,khula+1,band,str+'(');
        call(n,khula,band+1,str+')');
        }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        call(n,0,0,"");
        return ans;
    }
};