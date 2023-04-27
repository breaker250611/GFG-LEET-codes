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
        ListNode* slo =head;
        ListNode* fas = head;
        
        while(slo!=nullptr && fas!= NULL and fas->next!=nullptr){
            slo = slo->next;
            fas = fas->next->next;
            // if(fas->next) fas = fas->next;
            if(slo==fas) return true;
        }
        return false;
    }
};