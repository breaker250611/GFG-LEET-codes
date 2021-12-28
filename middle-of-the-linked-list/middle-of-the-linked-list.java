/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
     ListNode tempslw = head;
        ListNode tempfas = head;
        while(tempfas!=null&&tempfas.next!=null){
            tempfas = tempfas.next.next;
            tempslw = tempslw.next;
        }
        return tempslw;
    }
}