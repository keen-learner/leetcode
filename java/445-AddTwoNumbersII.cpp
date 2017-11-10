/*

You are given two non-empty linked lists representing two non-negative 
integers. The most significant digit comes first and each of their nodes 
contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, 
reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int c = 0; // carry
        ListNode dummy = new ListNode(0);
        while(l1!=null || c!=0 || l2!=null) {
            int a = l1!=null?l1.val:0;
            int b = l2!=null?l2.val:0;
            
            int sum = a+b+c;
            ListNode temp = new ListNode(sum%10);
            c = sum/10;
            temp.next = dummy.next;
            dummy.next = temp;
            l1 = l1!=null?l1.next:null;
            l2 = l2!=null?l2.next:null;
        }
        return dummy.next;
    }
    
    private ListNode reverse(ListNode l1) {
        ListNode prev = null;
        ListNode curr = l1;
        while(curr!=null) {
            ListNode t = curr.next;
            curr.next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }    
};

class Solution1 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        ListNode curr = l1;
        while(curr!=null) {
            s1.push(curr.val);
            curr = curr.next;
        }
        curr = l2;
        while(curr!=null) {
            s2.push(curr.val);
            curr = curr.next;
        }
        int c = 0; // carry
        ListNode dummy = new ListNode(0);

        while(!s1.isEmpty() || c!=0 || !s2.isEmpty()) {
            int a, b;
            if(s1.isEmpty()) { 
                a = 0;
            } else {
                a = s1.peek();
                s1.pop();
            }
            if(s2.isEmpty()) { 
                b = 0;
            } else {
                b = s2.pop();
            }
            int sum = a+b+c;
            ListNode temp = new ListNode(sum%10);
            c = sum/10;
            temp.next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;        
    }
}



