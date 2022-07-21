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
    ListNode* end = nullptr;
     ListNode* tail ;
    ListNode* reverse(ListNode* head,ListNode* prev) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr){
            tail = head;
        }
        reverse(head->next,head);
        head->next = prev;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        tail = nullptr;
        end = reverse(head,nullptr);
        return tail;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* after = nullptr;
        ListNode* tempo = nullptr;
        ListNode* strt = nullptr;
         end = nullptr;
        int itr =1;
        if(left==right) return head;
        ListNode* temp = head;
        while(temp){
            if(itr==left){
                if(tempo){
                    prev = tempo;
                    prev->next = nullptr;
                    strt = temp;
                }
                else{
                    cout<<"chck";
                    strt = temp;
                }
            }
            if(itr==right){
                if(temp->next!=nullptr){
                    after = temp->next;
                    temp->next = nullptr;
                    end = temp;
                }
                else{
                    end = temp;
                }
            }
            tempo = temp;
            temp = temp->next;
            itr++;
        }
        
        strt = reverseList(strt);
       
        if(prev!=nullptr){
            prev->next = strt;
            // strt = prev;
        }
         
        if(after){
            end->next = after;
        }
        return (left==1)?strt:head;
    }
};