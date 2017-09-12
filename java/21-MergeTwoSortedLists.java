/*

Merge two sorted linked lists and return it as a new list. The new list should be 
made by splicing together the nodes of the first two lists.

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
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

class Solution1 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode head = l1.val < l2.val?l1:l2;
        ListNode curr = l1.val < l2.val?l1:l2;
        if(l1.val < l2.val) l1 = l1.next;
        else l2 = l2.next;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            }
            else {
                curr.next = l2;
                l2 = l2.next; 
            }
            curr = curr.next;
        }
        curr.next = l1!=null?l1:l2;
        return head;
        
    }
}


