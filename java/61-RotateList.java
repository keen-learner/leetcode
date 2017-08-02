/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        int n = 1;
        ListNode curr = new ListNode(0);
        curr = head;
        while(curr.next != null) {
            ++n;
            curr = curr.next;
        }
        curr.next = head;
        ListNode newHead = new ListNode(0);
        k = k % n;
        curr = head;
        int count = 1;
        while(count != n-k) {
            curr = curr.next;
            ++count;
        }
        newHead = curr.next;
        curr.next = null;
        return newHead;
    }
}

