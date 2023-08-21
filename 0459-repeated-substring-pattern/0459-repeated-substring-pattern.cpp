class Solution {
public:
    bool repeatedSubstringPattern(string s) {
     
        for(int i = 0;i<s.size()/2;i++){
            string str = s.substr(0,i+1);
            
            if(s.size()%str.size()==0){
                int num = str.size();
                int numberoftimes = s.size()/num;
                string temp = "";
                while(numberoftimes--){
                    temp  = str+temp;
                }
                
                
                if(temp==s)return true;
            }
        }
        
        
        
        
        
        
        return false;
    }
};