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
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        
        for(int i = 0;i<prefix.size();i++){
            char ch = prefix[i];
            if(curr->mp.find(ch)==curr->mp.end()) return false;
            
            curr = curr->mp[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */