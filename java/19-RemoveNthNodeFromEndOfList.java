/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy;
        for(int i = 0; i<n; i++) {
            fast = fast.next; // we know fast always exist
        }
        ListNode slow = head;
        ListNode prev = dummy;
        while(fast.next!=null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next;
        }
        prev.next = slow.next;
        return dummy.next;
    }
}

class Solution1 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int k = n;
        ListNode curr = head;
        n = 0;
        while(curr != null) {
            curr = curr.next;
            ++n;
        }
        n = n-k+1;
        
        curr = head;
        ListNode prev = dummy;
        for(int i = 0; i<n-1; i++) {
            prev = curr;
            curr = curr.next;
        }
        prev.next = curr.next;
        return dummy.next;
    }
}


