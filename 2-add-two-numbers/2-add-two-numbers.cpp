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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *naya = new ListNode();
        ListNode *head = naya;
        int carry = 0;
        while(l1!=nullptr&&l2!=nullptr){
            naya->next = new ListNode();
            naya = naya->next;
            int temp = l1->val+l2->val;
            if(carry>0) temp +=carry;
            carry = temp/10;
            temp = temp%10;
            naya->val = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr){
            naya->next = new ListNode();
            naya = naya->next;
            int temp = l1->val;
            if(carry>0) temp+=carry;
            carry = temp/10;
            temp = temp%10;
            naya->val = temp;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            naya->next = new ListNode();
            naya = naya->next;
            int temp = l2->val;
            if(carry>0) temp+=carry;
            carry = temp/10;
            temp = temp%10;
            naya->val = temp;
            l2 = l2->next;
        }
        cout<<carry<<endl;
        if(carry>0){
                        naya->next = new ListNode();
            naya = naya->next;
            naya->val = carry;
            
        }
        return head->next;
    }
};