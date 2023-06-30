class Solution {
public:
    vector<vector<string>>ans;
    bool ispal(string s){
        int i = 0;
        int j = s.size()-1;
        
        while(i<j){
            if(s[i] !=s[j])return false;
            
            i++;
            j--;
        }
        return true;
    }
    void call(string s , int i ,vector<string>temp){
        if(i>=s.size()){
            if(temp.size()>0){
                ans.push_back(temp);
            }
        return ;
        }
        
        string str = "";
        for(int k = i;k<s.size();k++){
            str += s[k];
            
            if(ispal(str)){
                temp.push_back(str);
                call(s,k+1,temp);
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        
        call(s,0,{});
        
        return ans;
    }
};