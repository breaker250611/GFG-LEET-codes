class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        
        vector<string>temp;
        int length = 0;
        int totsize = 0;
        for(int i = 0;i<words.size();i++){
            int wordlength = words[i].size();
            if(totsize == 0){
                length += wordlength;
                temp.push_back(words[i]);
                
                totsize += (wordlength);
            }
            else if(totsize + wordlength+1<=maxWidth){
                length += wordlength;
                temp.push_back(words[i]);
                
                totsize += (wordlength+1);
            }
            else{
                 int totstr = temp.size();
                if(totstr==1){
                    int spac = maxWidth - length;
                    
                    string res = "";
                    res += temp[0];
                    for(int k = 0;k<spac;k++){
                        res += ' ';
                    }
                    
                    ans.push_back(res);
                }
                else{
                    int spac = (maxWidth-length)/(totstr-1);
                    int extra = (maxWidth-length)%(totstr-1);
                    string res = "";
                    for(int k = 0;k<temp.size();k++){
                        res += temp[k];
                        if(res.size()==maxWidth)break;
                        for(int l = 0;l<spac;l++){
                            res += ' ';
                        }
                        if(extra){
                            res += ' ';
                            extra--;
                        }
                    }
                    
                    ans.push_back(res);
                    
                }
                
                length = 0;
                totsize = 0;
                temp.clear();
            }
             if(totsize == 0){
                length += wordlength;
                temp.push_back(words[i]);
                
                totsize += (wordlength);
            }
            
        }
        if(temp.size()){
            
            string res = "";
            
            for(int i = 0;i<temp.size();i++){
                res += temp[i];
                if(i<temp.size()-1){
                    res += ' ';
                }
            }
            while(res.size()<maxWidth){
                res += ' ';
            }
            
            ans.push_back(res);
            
        }
        
        return ans;
        
    }
};