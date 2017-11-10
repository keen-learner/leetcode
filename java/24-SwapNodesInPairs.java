/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values 
in the list, only nodes itself can be changed.

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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        ListNode curr2 = head.next;
        int i = 0;
        while(curr2!=null) {
            prev.next = curr2;
            ListNode t = curr2.next;
            curr2.next = curr;
            curr.next = t;
            prev = curr;
            curr = t;
            // if(t==null) break; // can use these two lines too
            // curr2 = t.next; // if only 'if..' there test case [1,2] problem 
            curr2 = t!=null?t.next:null; 
        }
        return dummy.next;
    }
}
