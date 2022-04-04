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
       vector<int>vp;
        ListNode* n = head;
        while(n!=nullptr){
            vp.push_back(n->val);
            n = n->next;
        }
        // vp.swap(vp.begin()+k,vp.end()-k);
        int last = vp.size()-k;
        int temp = vp[k-1];
        vp[k-1] = vp[last];
        vp[last]=temp;
        // for(auto &x:vp) cout<<x<<endl;
        n =head;
        int i = 0;
        while(n!=nullptr){
            n->val  = vp[i++];
            n = n->next;
        }
    return head;
    }
};