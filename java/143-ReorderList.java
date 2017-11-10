/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode slow = head;
        ListNode fast = head;
        // ListNode prev = null;
        while(fast != null && fast.next != null) {
            // prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode tail = fast==null?slow:slow.next;
        ListNode curr2 = reverse(tail);
        ListNode curr = head;
        while(curr2!=null) {
            ListNode t = curr.next;
            ListNode t2 = curr2.next;
            curr.next = curr2;
            curr2.next = t;
            curr = t;
            curr2 = t2;
        }
        curr.next = null;
    }
    
    private ListNode reverse(ListNode tail){
        ListNode prev = null;
        ListNode curr = tail;
        while(curr != null) {
            ListNode t = curr.next;
            curr.next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
}
