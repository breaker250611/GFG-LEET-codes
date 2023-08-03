class Trie{
  public:
    map<char,Trie*>mp={};
    bool worddone = false;
    string wordd = "";
  
    Trie(){
        
    }
    
    void insert(string word){
        Trie* curr =this;
        
        
        for(auto&it:word){
            if(curr->mp.find(it)==curr->mp.end()){
                curr->mp[it] = new Trie();
                // curr->sum += val;
            }
            curr = curr->mp[it];
        }
        curr->worddone = true;
        curr->wordd = word;
    }

    
};


class Solution {
public:
    
    
    string call(string word,int i,Trie* root){
        
        
        if(root->worddone==true){
            return root->wordd;
        }
        if(i>word.size() or root->mp.find(word[i])==root->mp.end()){
            // cout<<word<<" = "<<i<<endl;
            return "";
        }
        
        return call(word,i+1,root->mp[word[i]]);
        
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for(auto &it:dictionary){
            root->insert(it);
        }
        vector<string> word;
        string temp="";
        for(int i = 0;i<sentence.size();i++){
            if(sentence[i]==' '){
                word.push_back(temp);
                temp = "";
                continue;
            }
            temp += sentence[i];
        }
        word.push_back(temp);
        sentence = "";
        for(int i = 0;i<word.size();i++){
            string temp = word[i];
            string come = call(temp,0,root);
            // cout<<come<<endl;
            
            if(come.size()==0){
                come = temp;
            }
            sentence +=come;
           if(i<word.size()-1) sentence += " ";
        }
        
        return sentence;
    }
};





