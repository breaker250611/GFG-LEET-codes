/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void attach(Node *head){
        Node *temp = head;
        while (temp){
            Node *nxt = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nxt;
            temp = nxt;
        }
    }
    
    void attachrandom(Node *head){
        Node *temp = head;
        while (temp){
            if (temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }
    
    Node* attachnext(Node *head){
        Node *temp = head;
        Node *ans = head->next;
        while (temp and temp->next){
            Node *nxt = temp->next;
            temp->next = nxt->next;
            temp = nxt;
        }
        return ans;
    }
    
    Node* copyRandomList(Node* head) {
        
        if (!head)
            return NULL;
        
        attach(head);
        attachrandom(head);
        Node* ok = attachnext(head);
        return ok;
    }
};