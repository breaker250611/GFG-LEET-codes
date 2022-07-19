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
    ListNode* swapNodes(ListNode* head, int k) {
                ListNode *slow = head;
        ListNode *ptr = head;
        ListNode *first = NULL;
        
        for (int i = 1 ; i <= k ; i++){
            first = ptr;
            ptr = ptr->next;
        }
        
        
        if (!ptr){
            swap(head->val , first->val);
            return head;
        }
        
        while (ptr){
            ptr = ptr->next;
            slow = slow->next;
        }
        swap(first->val , slow->val);
        return head;
    }
};