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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int sum = 0;
        ListNode* temp = new ListNode(0);
        mp[0] = temp;
        temp->next = head;
        
        
        while(head !=NULL){
            int valu = head->val;
            sum += valu;
            if(mp.find(sum)!=mp.end()){
                ListNode* prev = mp[sum];
                int nikal = sum;
                prev  = prev->next;
                while(prev != head){
                    nikal += prev->val;
                    mp.erase(nikal);
                    prev  = prev->next;
                }
                mp[sum]->next = head->next;
            }
            else{
                mp[sum] = head;
            }
            head = head->next;
        }
        return temp->next;
    }
};