class Trie{
  public:
    map<char,Trie*>mp={};
    bool worddone = false;
    map<char,int>sum {};
    Trie(){
        
    }
    
    void insert(string word,int val){
        Trie* curr =this;
        
        
        for(auto&it:word){
            if(curr->mp.find(it)==curr->mp.end()){
                curr->mp[it] = new Trie();
                // curr->sum += val;
            }
            curr->sum[it] +=val;
            curr = curr->mp[it];
        }
        curr->worddone = true;
    }
    
    void overr(string word,int val,int old){
        Trie* curr = this;
        
        
        for(auto&it:word){
            if(curr->mp.find(it)!=curr->mp.end()){
                curr->sum[it] -= old;
            }
           curr->sum[it] +=val;
            curr = curr->mp[it];
        }
    }
    
    
    int pref(string word){
        int ans = 0 ;
        Trie* curr = this;
        for(auto&it:word){
            if(curr->mp.find(it)==curr->mp.end())return 0;
            ans = curr->sum[it];
            curr = curr->mp[it];
        }
        
        return ans;
    }
    
};



class MapSum {
public:
    map<string,int>mp={};
    Trie* root = new Trie();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        MapSum* temp = this;
        if(temp->mp.find(key)==temp->mp.end()){
            root->insert(key,val);
        }
        else{
            root->overr(key,val,temp->mp[key]);
        }
        
    temp->mp[key] = val;
    }
    
    int sum(string prefix) {
        return root->pref(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */