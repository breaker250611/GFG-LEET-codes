class Trie {
public:
    map<char,Trie*>mp = {};
    bool wordisdone = false;
    Trie() {
        
    }
    
    void insert(string word) {
        
        Trie* curr = this;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(curr->mp.find(ch)==curr->mp.end()){
                curr->mp[ch] = new Trie();
            }
            
            curr = curr->mp[ch];
        }
        curr->wordisdone = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            
            if(!curr->mp.count(ch))
                return false;
            
            curr = curr->mp[ch];
        }
        return curr->wordisdone;
        
        
    }
    
};
class Solution {
public:
    int maxi;
    string str;
    void dfs(Trie* root,string temp,int cnt){
        if(cnt>maxi){
            maxi = cnt;
            str = temp;
        }
        
        
        for(int i = 0;i<26;i++){
            char ch = 'a'+i;
            
            if(root->mp.find(ch)!=root->mp.end()){
                Trie* templ = root->mp[ch];
                if(templ->wordisdone){
                    dfs(templ,temp+ch,cnt+1);
                }
            }
        }
    }
    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for(int i = 0;i<words.size();i++){
            root->insert(words[i]);
        }
        maxi = 0;
        str = "";
        dfs(root,"",0);
            
        return str;
        
    }
};