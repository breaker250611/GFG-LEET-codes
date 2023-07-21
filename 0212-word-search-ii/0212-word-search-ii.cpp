class Trie{
  public:
    map<char,Trie*>mp={};
    bool worddone = false;
  
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
    }

    
};
class Solution {
public:
    vector<string>ans;
    void dfs (vector<vector<char>> & board, string str,Trie* &root,int i , int j){
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]==0 or  root->mp.find(board[i][j])==root->mp.end()){
            return ;
        }
        char ch = board[i][j];
        str += ch;
        board[i][j] = 0;
        
        if(root->mp[ch]->worddone == true){
            ans.push_back(str);
            root->mp[ch]->worddone = false;
        }
        dfs(board,str,root->mp[ch],i+1,j);
        dfs(board,str,root->mp[ch],i,j+1);
        dfs(board,str,root->mp[ch],i-1,j);
        dfs(board,str,root->mp[ch],i,j-1);
        
        board[i][j] = ch;
        return;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        
        for(auto &it:words){
            root->insert(it);
        }
        ans.clear();
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                dfs(board,"",root,i,j);
            }
        }
        
        return ans;
    }
};