/*

A linked list is given such that each node contains an additional random 
pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */

public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null) return null;
        for(RandomListNode l1 = head; l1!=null; l1 = l1.next.next) {
            RandomListNode t = new RandomListNode(l1.label);
            t.next = l1.next;
            l1.next = t;
        }
        RandomListNode newhead = head.next;
        for(RandomListNode l1 = head; l1!=null; l1 = l1.next.next) {
            if(l1.random != null) {
                l1.next.random = l1.random.next;
            }
        }
        RandomListNode l2 = null;
        for(RandomListNode l1 = head; l1!=null; l1 = l1.next) {
            l2 = l1.next;
            l1.next = l2.next;
            if(l2.next != null) l2.next = l2.next.next;
        }
        return newhead;
    }
}

class Solution1 {
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null) return null;
        Map<RandomListNode, RandomListNode> m = new HashMap<RandomListNode, RandomListNode>();
        for(RandomListNode l1 = head; l1!=null; l1 = l1.next) {
            m.put(l1, new RandomListNode(l1.label));
        }
        for(RandomListNode l1 = head; l1!=null; l1 = l1.next) {
            RandomListNode n = m.get(l1);
            n.next = m.get(l1.next);
            n.random = m.get(l1.random);
        }

        return m.get(head);
    }
}
