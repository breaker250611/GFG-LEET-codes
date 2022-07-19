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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
        ListNode *A = headA , *B = headB;
        bool first = false , second = false;
        
        while (A and B){
            
            if (A == B)
                return A;
            
            A = A->next;
            B = B->next;
             
            if (!A && !first){
                A = headB;
                first = true;
            }
            if (!B and !second){
                B = headA;
                second = true;
            }
        }
        return NULL;
    }
};