
class LRUCache {
   public:
    struct Node{
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(){
            key = 0;
            val = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int key1,int value){
            this->key = key1;
            this->val = value;
            next = NULL;
            prev = NULL;
        }
    };
    int cap;
    unordered_map<int,Node*> mp;
    Node *head = new Node();
    Node *tail  = new Node();
    void addNode(Node *node){
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    void delNode(Node *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    
    LRUCache(int capacity) {
        cap = capacity;
        head ->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *temp = mp[key];
            int val = temp->val;
            delNode(temp);
            mp.erase(key);
            addNode(temp);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp = mp[key];
            temp->val = value;
            delNode(temp);
            mp.erase(key);

            addNode(temp);
            mp[key] = head->next;
            return;
        }
        // cout<<cap<<endl;
        if(mp.size() >= cap){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
        // if(mp.size()==4) cout<<"true"<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */