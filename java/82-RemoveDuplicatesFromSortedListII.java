/*

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
        if (head == null) return null;
    
        if (head.next != null && head.val == head.next.val) {
            while (head.next != null && head.val == head.next.val) {
                head = head.next;
            }
            return deleteDuplicates(head.next);
        } 
        head.next = deleteDuplicates(head.next);
        return head;
    }
}

class Solution1 {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        boolean flag = false;
        while(curr != null) {
            while(curr.next != null && curr.val == curr.next.val) {
                ListNode t = curr.next;
                curr.next = t.next;
                flag = true;
            }
            if(flag) { //curr is a duplicate value
                ListNode t = curr.next;
                prev.next = t;
                curr = t;
            }
            else {
                prev = curr;
                curr = curr.next;
            }
            flag = false;
        }
        return dummy.next;
    }
}

