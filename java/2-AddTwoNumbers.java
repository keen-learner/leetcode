/*

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single 
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int c = 0; // carry
        while(l1!=null || l2!=null || c!=0) {
            int sum = c + (l1==null?0:l1.val) + (l2==null?0:l2.val);
            curr.next = new ListNode(sum%10);
            curr = curr.next;
            c = sum/10;
            l1 = l1==null?null:l1.next;
            l2 = l2==null?null:l2.next;
        }
        return dummy.next;
    }
}
