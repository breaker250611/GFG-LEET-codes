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
    ListNode* reverseList(ListNode* head) {
        ListNode* fir = head;
        if(head==nullptr or head->next==nullptr)return head;
        ListNode* sec = head->next;
        ListNode* thir = sec->next;
        fir->next = nullptr;
        while(sec!=nullptr){
            sec->next = fir;
            fir = sec;
            sec = thir;
            if(thir!=nullptr)thir = thir->next;
        }
        return fir;
    }
};