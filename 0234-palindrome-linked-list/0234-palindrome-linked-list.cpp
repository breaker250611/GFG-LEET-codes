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

//space o(1);
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* Next;
        ListNode* previous = NULL;
        
        
        while(curr != NULL){
            Next = curr->next;
            curr->next = previous;
            previous = curr;
            curr =Next;
        }
        
        head = previous;
        return head;
        
    }
    bool isPalindrome(ListNode* head) {
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL){
            
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* mid = slow;
        mid->next = reverseList(mid->next);
        mid = mid->next;
        
        while(mid != NULL){
            if(head->val != mid->val){
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
        
    }
};