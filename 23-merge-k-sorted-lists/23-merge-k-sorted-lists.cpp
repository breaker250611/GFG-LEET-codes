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
    
     ListNode *merge(ListNode *l1 , ListNode *l2){
        ListNode *D = new ListNode(-1);
        ListNode *ptr = D;
    
        
        while (l1 and l2){
            
            if(l1->val <= l2->val){
              ptr->next = l1;
              l1 = l1->next;
            }
            else {
              ptr->next = l2;
              l2 = l2->next;
            }
            ptr = ptr->next;
        }
        
        if (l1)
            ptr->next = l1;
        if (l2)
            ptr->next = l2;
        
        return D->next;
    }
    
    
    ListNode* mergesort(int s, int e,vector<ListNode*>&lists){
        if(s>e) return nullptr;
        if(s==e)return lists[s];
        int mid = (s+e)/2;
                cout<<"he";
        ListNode* l1 = mergesort(s,mid,lists);
        ListNode* l2 = mergesort(mid+1,e,lists);

        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      return mergesort(0 , lists.size()-1 , lists);   
    }
};