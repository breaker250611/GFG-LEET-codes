struct Node {
    vector<Node *> next; 
    bool is_end; 

    Node() {
        next = vector<Node *>(26, nullptr);
        is_end = false;
    }
    bool contains(char w) {
        return next[w - 'a'] != nullptr;
    }
    Node* get(char w) {
        return next[w - 'a'];
    }
    void put(char w, Node* node) {
        next[w - 'a'] = node;
    }
    void set_end() {
        is_end = true;
    }
    void end_back() {
        is_end = false;
    }
};

class Trie {
    public: 
    Node *root; 
    Trie() {
        root = new Node();
    }
    void insert(const string &s) {
        auto node = root;
        for (const auto& w: s) {
            if (!node->contains(w)) {
                node->put(w, new Node());
            }
            node = node->get(w);
        }
        node->set_end();
    }
    
    bool find(const string& s) {
        auto node = root; 
        for (const auto& w: s) {
            if (!node->contains(w)) {
                return false;
            }
            node = node->get(w);
        }
        return true;
    }
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
vector<vector<bool>> used;
int R, C;

class Solution {
    public:
    Trie *t;
    vector<string> ans;
    string temp;
    vector<vector<char>> board;

    void dfs(int i, int j, Node *node) {
        if (i < 0 or j < 0 or i >= R or j >= C or 
            !node->contains(board[i][j]) or 
            used[i][j]) return; 
        
        
        used[i][j] = true;
        
        for (int d = 0; d < 4; d++) {
            int r = i + dr[d];
            int c = j + dc[d];
            
            Node* NEXT = node->get(board[i][j]);
            temp += board[i][j];
            
            if (NEXT->is_end) {
                ans.push_back(temp);
                NEXT->end_back();
            }
            
            dfs(r, c, node->get(board[i][j]));
            temp.pop_back();
        }
        
        
        used[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        t = new Trie(); 
        for (const auto& word: words) {
            t->insert(word);
        }

        this->board = board;
        R = board.size(); 
        C = board.front().size();


        used = vector<vector<bool>>(R, vector<bool>(C, false));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (t->root->contains(board[i][j])) {
                    dfs(i, j, t->root);
                }
            }
        }
        
        return ans;
    }
};