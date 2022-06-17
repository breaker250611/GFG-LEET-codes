struct Node{
    Node *links[26];
    bool end; 
    
    Node(){
        for (int i = 0 ; i < 26 ; i++)
            links[i] = NULL;
        end = false;
    }
    
    bool not_contain(char ch){
        return links[ch-'a'] == NULL;
    }
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void insert(char ch , Node *node){
        links[ch-'a'] = node;
    }
    
    void setEnd(){
        end = true;
    }
    
    bool getEnd(){
        return end;
    }    
};

class Solution {
    private : 
    Node *root;
    string ans;
    int mx;
public:  
    void dfs(Node *node , int val , string s){
        if (val > mx){
            ans = s;
            mx = val;
        }
        
        for (char i = 'a' ; i <= 'z' ; i++){
            if (node->contains(i)){
               Node *curr = node->get(i);
               if (curr->getEnd()){
                  dfs(curr , val+1 , s + i);  
               } 
            }
        }
        return;
    }

    void insert(string a){
        Node *node = root;
        for (auto x : a){
            if (node->not_contain(x)){
                node->insert(x , new Node());
            }
            node = node->get(x);
        }
        node->setEnd();
    }

    string longestWord(vector<string>& words) {
        
        mx = 0;
        ans = "";
        root = new Node();
        for (auto x : words){
            insert(x);
        }
        
        dfs(root , 0 , "");
        return ans;
    }
};