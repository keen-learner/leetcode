/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null) return null;
        // set two runners
        ListNode slow = head;
        ListNode fast = head;

        // fast runner move 2 steps at one time while slow runner move 1 step,
        // if traverse to a null, there must be no loop
        while (fast != null && fast.next != null) {
          slow = slow.next;
          fast = fast.next.next;
          if (slow == fast) { //cycle found
                fast = head;
                while(slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
            return slow;
          }
        }
        return null;        
    }
}
