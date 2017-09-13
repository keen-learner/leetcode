/*

Sort a linked list in O(n log n) time using constant space complexity.

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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode head1 = head;
        ListNode head2 = null;
        if(fast == null) { //even length case
            head2 = slow;
            prev.next = null;
        }
        else {
            head2 = slow.next;
            slow.next = null;
        }
        return mergeTwoLists(sortList(head1), sortList(head2));
        
    }
    
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode head = l1.val<l2.val?l1:l2;
        if(l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
        }
        else l2.next = mergeTwoLists(l1, l2.next);
        return head;        
    }
}
