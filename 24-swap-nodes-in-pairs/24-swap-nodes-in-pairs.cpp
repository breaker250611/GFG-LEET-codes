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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
     ListNode* dummy = new ListNode(0);
        dummy->next = head;
     ListNode* curr = dummy;
        ListNode* next = head->next;
        
        while(head!=nullptr && head->next!=nullptr){
            curr->next = next;
            head->next = next->next;
            next->next = head;
            curr = head;
            head = head->next;
            if(head==nullptr)break;
            next = head->next;
        }
        return dummy->next;
        
    }
};