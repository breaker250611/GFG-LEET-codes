class WordDictionary {
public:
    map<char,WordDictionary*>mp;
    bool worddone = false;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(curr->mp.find(ch)==curr->mp.end()){
                curr->mp[ch] = new WordDictionary();
            }
            
            curr = curr->mp[ch];
        }
        
        curr->worddone = true;
    }
    bool call(string word,WordDictionary* curr,int i ){
        
        if(i==word.size() and curr->worddone)return true;
        if(i>=word.size() or (word[i]!='.' and curr->mp.find(word[i])==curr->mp.end()))return false;
        
        if(word[i] != '.'){
            return call(word,curr->mp[word[i]],i+1);
        }
        int ans = false;
        
        for(auto&it:curr->mp){
            ans ^= call(word,it.second,i+1);
            if(ans==true)return ans;
        }
        
        return ans;
        
    }
    bool search(string word) {
        WordDictionary* curr = this;
        return call(word,curr,0);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */