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
    ListNode* temphead;
    ListNode* nex = NULL;
    
    ListNode* call(ListNode* head,int k){
        
        if(k==0){
            temphead = head;
            nex = head->next;
            return head;
        }
        
        ListNode* curr = call(head->next,k-1);
        
        curr->next = head;
        // cout<<head->val<<endl;
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right or head==NULL)return head;
        
        ListNode*prev =NULL;
        ListNode* curr = head;
        int count = 1;
        while(count <left){
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        ListNode* temptail = call(curr,right-left);
        // cout<<prev->val<<endl;
        if(prev != NULL){
            prev->next = temphead;
        }
        temptail->next = nex;
        if(prev==nullptr)return temphead;
        return head;
        
        
        
    }
};