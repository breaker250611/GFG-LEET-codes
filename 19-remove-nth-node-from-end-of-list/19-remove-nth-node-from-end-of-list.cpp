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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* chota = head;
        ListNode* bada = head;
        while(n--){
            bada= bada->next;
        }
        if(bada==nullptr)return head->next;
        while(bada!=nullptr){
            if(bada->next==nullptr)break;
            chota = chota->next;
            bada = bada->next;
        }
        chota->next = chota->next->next;
        return head;
    }
};