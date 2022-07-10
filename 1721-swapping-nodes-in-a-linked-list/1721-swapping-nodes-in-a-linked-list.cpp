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
        int count= 0;
        
        ListNode* head1 = head;
        while(head!=nullptr){
            count++;
            head = head->next;
        }
        cout<<count<<endl;
        head = head1;
        int pehla = k-1;
        int dusra = count-k;
        ListNode*pehla1 = nullptr;
        ListNode * dusra1 = nullptr;
        
        for(int i = 0;i<count;i++){
            if(i==pehla){
                pehla1 = head; 
            }
             if(i==dusra){
                dusra1 = head;
                
               
                
            }
            head = head->next;
        }
         int temp = dusra1->val;
                dusra1->val = pehla1->val;
                pehla1->val = temp;
        return head1;
        
    }
};