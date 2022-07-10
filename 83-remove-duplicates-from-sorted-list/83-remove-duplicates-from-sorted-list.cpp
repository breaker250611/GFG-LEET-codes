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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int>st;
        ListNode* head1 = head;
        while(head!=nullptr and head->next!=nullptr){
            int val = head->val;
            st.insert(val);
            int nex = head->next->val;
            if(st.find(nex)!=st.end()){
                head->next = head->next->next;
                continue;
            }
            head= head->next;
        }
        return head1;
    }
};