/*
Merge k sorted linked lists and return it as one sorted list. 
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// Time:  O(n * logk)
// Space: O(1)
// Merge two by two solution.
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0 ) return null;
        if(lists.length == 1) return lists[0];
        return helper(lists, 0 , lists.length-1);
    }
    private ListNode helper(ListNode[] lists, int l, int r) {
        if(l>r) return null;
        if(l == r) return lists[l];
        int m = l + (r-l)/2;
        return mergeTwoLists(helper(lists, l, m), helper(lists, m+1, r));
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

// Time:  O(n * logk)
// Space: O(logk)
// Divide and Conquer solution.
class Solution1 {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0 ) return null;
        if(lists.length == 1) return lists[0];
        int l = 0;
        int r = lists.length-1;
        while(r>0) {
            if(l >=r) l = 0;
            else {
                lists[l] = mergeTwoLists(lists[l], lists[r]);
                ++l;
                --r;
            }
        }
        return lists[0];
    }
    
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
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


