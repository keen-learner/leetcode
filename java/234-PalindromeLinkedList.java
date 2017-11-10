/*

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

// http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    public boolean isPalindrome(ListNode head) {
        // Reverse the first half list.
        ListNode prev = null;
        ListNode fast = head;
        ListNode slow = head;
        while (fast!=null && fast.next!=null) {
            fast = fast.next.next;
            ListNode temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }

        // If the number of the nodes is odd,
        // set the head of the tail list to the next of the median node.
        ListNode tail = fast!=null ? slow.next : slow;

        // Compare the reversed first half list with the second half list.
        // And restore the reversed first half list.
        boolean res = true;
        while (prev!=null) {
            res = res && prev.val == tail.val;
            ListNode temp = prev.next;
            prev.next = slow;
            slow = prev;
            prev = temp;
            tail = tail.next;
        }
            
        return res;           
    }
}


