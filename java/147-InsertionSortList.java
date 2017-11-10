/*

Sort a linked list using insertion sort.

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
    public ListNode insertionSortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        // dummy.next = head; //DONT DO THIS else infinite loop [1,1]
        ListNode curr = head; //insert curr
        ListNode pre = dummy; // b/w pre and pre.next
        while(curr!=null) {
            while(pre.next != null && pre.next.val < curr.val) pre = pre.next;
            ListNode temp = curr.next;
            curr.next = pre.next;
            pre.next = curr;
            pre = dummy;
            curr = temp;
        }
        return dummy.next;
    }
}
