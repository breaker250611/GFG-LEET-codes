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
    bool isPalindrome(ListNode* head) {
        vector<int>vc;
        ListNode* temp = head;
        
        while(temp!=nullptr){
            
            vc.push_back(temp->val);
            temp = temp->next;
        }
        
        int i = 0;
        int h = vc.size()-1;
        
        while(i<=h){
            if(vc[i]==vc[h]){
                i++;
                h--;
            }
            else return false;
        }
        return true;
    }
};