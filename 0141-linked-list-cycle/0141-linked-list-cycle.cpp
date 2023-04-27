/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(slow!=NULL and fast!=NULL and fast->next != NULL){
            fast = fast->next->next; //2x
            slow = slow->next;  // x
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};