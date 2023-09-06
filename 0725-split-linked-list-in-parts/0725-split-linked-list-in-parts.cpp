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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        vector<ListNode*>ans;
        
        int harpart = count/k;
        int add = count%k;
        
        temp = head;
        while(temp != NULL){
            
            int lena = harpart;
            // if(add>0){
            //     lena += 1;
            //     add--;
            // }
            ans.push_back(temp);
            ListNode* prev = NULL;
            
            while(lena>0 and temp !=NULL){
                prev = temp;
                temp = temp->next;
                lena--;
            }
            if(add and temp != NULL){
                prev = temp;
                temp = temp->next;
                add--;
            }
            prev->next = NULL;
            // while(lena>=1){
            //     temp = temp->next;
            // }
        }
        
        while(ans.size() <k){
            ans.push_back(NULL);
        }
        return ans;
    }
};