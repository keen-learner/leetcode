/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode prev = head;
        ListNode curr = head.next;
        while(curr != null) {
            if(curr.val == prev.val) {
                ListNode t = curr.next;
                prev.next = t;
                curr = t;
            }
            else {
                prev = curr;
                curr = prev;
            }
        }
        return head;
    }
}
