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
        
        ListNode* dumy = new ListNode();
        ListNode* head = dumy;
        
        while(list1!=nullptr || list2!= nullptr){
            
            if(list1==nullptr){
                    dumy->next = list2;
                    list2 = list2->next;
            }
            else if(list2==nullptr){
                    dumy->next = list1;
                    list1 = list1->next;
            }  
            else{
                if(list1->val>=list2->val){
                    dumy->next = list2;
                    list2 = list2->next;
                }
                else{
                    dumy->next = list1;
                    list1 = list1->next;
                  
                }

            }
              dumy = dumy->next;

        }
        return head->next;
    }
};