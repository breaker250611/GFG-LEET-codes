/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slo = head;
        ListNode fas = head;
    while(fas!=null&&fas.next!=null&&fas.next.next!=null&&slo.next!=null){
            fas = fas.next.next;
            slo = slo.next;
            if(fas==slo) return true;
        }
        return false;
    }
}