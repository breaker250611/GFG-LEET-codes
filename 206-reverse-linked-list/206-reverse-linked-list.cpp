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
    ListNode* tail ;
    ListNode* reverse(ListNode* head,ListNode* prev) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr){
            tail = head;
        }
        reverse(head->next,head);
        head->next = prev;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        tail = nullptr;
        reverse(head,nullptr);
        return tail;
    }
};