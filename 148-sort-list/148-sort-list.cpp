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
    ListNode* mid(ListNode* head){
        ListNode* slow=head,*fast = head,*tail = head;
        while(fast and fast->next){
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tail->next = NULL;
        return slow;
    }
    ListNode *merge(ListNode *l1 , ListNode *l2){
        
        ListNode *D = new ListNode(-1);
        ListNode *ptr = D;
        
        while (l1 and l2){
            if (l1->val <= l2->val){
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            }
            else {
               ptr->next = l2;
               ptr = l2;
               l2 = l2->next;
            }            
        }
        
        if (l1){
            ptr->next = l1;
        }
        else if (l2){
            ptr->next = l2;
        }
        return D->next;        
    }
    
    ListNode* mergesort(ListNode* head){
        if(!head or !head->next) return head;
        
        ListNode* midd = mid(head);
        ListNode* pehla_half = mergesort(head);
        ListNode* dusra_half = mergesort(midd);
        
        return merge(pehla_half , dusra_half);
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};