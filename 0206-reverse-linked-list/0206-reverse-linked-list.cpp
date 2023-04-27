/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* tail;
    ListNode* reverseList(ListNode* head) {
    
        
        fun(head,nullptr);
        head = tail;
        return head;
        
    }
    
    
    void fun(ListNode* curr,ListNode* peechla){
        
        if(curr==NULL){
            return ;
        }
        if(curr->next ==NULL){
            tail = curr;
        }
        fun(curr->next,curr);
        curr->next = peechla;
    }
};