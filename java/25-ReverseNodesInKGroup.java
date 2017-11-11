/*

Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list.

k is a positive integer and is less than or equal to the length of the 
linked list. If the number of nodes is not a multiple of k then 
left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) return null;
        ListNode dummy = new ListNode(0); 
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        while(curr!=null) {
            for (int i=0; i < k; ++i) {
                if (curr == null) return dummy.next; // nothing to do; list too short
                curr = curr.next;
            }    
            // curr is k+1 th node
            ListNode t = reverse(prev.next, curr);
            ListNode new_prev = prev.next;
            prev.next = t;
            prev = new_prev;
        }
        
        return dummy.next;
    }
    
    ListNode reverse(ListNode first, ListNode last) {
        ListNode prev = last; // NOTE: V. IMP
        while ( first != last ) {
            ListNode tmp = first.next;
            first.next = prev;
            prev = first;
            first = tmp;
        } 
        return prev;
    }
}

class Solution1 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode node=head;
        for (int i=0; i < k; ++i) {
            if (node == null) return head; // nothing to do; list too short
            node = node.next;
        }
        // node here points to k+1 th node    
        ListNode new_head = reverse(head, node);
        head.next = reverseKGroup( node, k);
        return new_head;
    }
    
    ListNode reverse(ListNode first, ListNode last) {
        ListNode prev = last; // NOTE: V. IMP
        while ( first != last ) {
            ListNode tmp = first.next;
            first.next = prev;
            prev = first;
            first = tmp;
        } 
        return prev;
    }
}
