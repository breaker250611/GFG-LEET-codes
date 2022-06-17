struct Node{
  
    Node *links[26];
    int end;
    int tot;
    
    Node(){
        for (int i = 0 ; i < 26 ; i++)
            links[i] = NULL;
        end = 0;
        tot = 0;
    }
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void create(char ch , Node *node){
        links[ch-'a'] = node;
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void increase(int plus , int minus){
        tot = tot + plus - minus;
    }
    
    void End(int plus , int minus){
        end = end + plus - minus;
    }
    
    int getEnd(){
        return end;
    }
    int getTot(){
        return tot;
    }
};
class MapSum {

private:
    Node *root;
    
public:
    MapSum() {
        root = new Node();
    }
    
    int search(string key){
        Node *node = root;
        for (auto x : key){
            if (!node->contains(x)){
                return 0;
            }
            node = node->get(x);
        }
        return node->getEnd();
    }
    
    void insert(string key, int val) {
        int minus = search(key);
        Node *node = root;
        for (auto x : key){
            if (!node->contains(x)){
                node->create(x , new Node());
            }
            node = node->get(x);
            node->increase(val , minus);
        }
        node->End(val , minus);
        
        return;
    }
    
    int sum(string prefix) {
         Node *node = root;
         for (auto x : prefix){
            if (!node->contains(x)){
                node->create(x , new Node());
            }
            node = node->get(x);
            //node->increase(val , minus);
        }
        return node->getTot();
    }
};