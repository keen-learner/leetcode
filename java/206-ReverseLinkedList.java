/*

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode t = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return t;
    }
}


class Solution1 {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode prev = null;
        ListNode curr = head;
        // curr = head;
        while(curr != null) {
            ListNode t = curr.next;
            // t = curr.next;
            curr.next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
}
