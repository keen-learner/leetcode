/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        for(int i = 0; i < m-1; i++) {
            prev = prev.next;
            curr = curr.next;
        }
        ListNode tm_1 = prev; //m-1 node
        ListNode t = null;
        for(int i = 0; i <= n-m; i++) {
            t = curr.next;
            curr.next = prev;
            prev = curr;
            curr = t;
        }
        tm_1.next.next = curr;
        tm_1.next = prev;
        return dummy.next;
    }
}
