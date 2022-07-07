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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        
        ListNode* naya = new ListNode();
        ListNode* head = naya;
        
        while(list1!=nullptr || list2!= nullptr){
            naya->next = new ListNode();
            naya = naya->next;
            
            if(list1==nullptr){
                    naya->val = list2->val;
                list2 = list2->next;
            }
            else if(list2==nullptr){
                    naya->val = list1->val;
                list1 = list1->next;
            }
            else{
                if(list1->val>=list2->val){
                    naya->val = list2->val;
                    list2 = list2->next;
                }
                else{
                    naya->val = list1->val;
                  list1 = list1->next;
                  
                }
            }
        }
        return head->next;
    }
};