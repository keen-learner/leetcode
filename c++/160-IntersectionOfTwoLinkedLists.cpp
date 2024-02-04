/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA;
        ListNode *cur2 = headB;
        while(cur1 != cur2) {
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;
    }
};


class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA;
        ListNode *cur2 = headB;
        if(headA == headB) return headA;
        int count1 = 0;
        int count2 = 0;
        while(cur1) {
            ++count1;
            cur1 = cur1->next;
        }
        while(cur2) {
            ++count2;
            cur2 = cur2->next;
        }
        cur1 = headA;
        cur2 = headB;
        if(count1 > count2) {
            int diff = count1-count2;
            while(diff) {
                cur1 = cur1->next;
                --diff;
            }
        }
        else {
            int diff = count2-count1;
            while(diff) {
                cur2 = cur2->next;
                --diff;
            }
        }
        while(cur1 && cur2){
            if(cur1 == cur2) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
        while (curA && curB) {
            if (curA == curB) {
                begin = curA;
                break;
            }
   
            if (curA->next) {
                curA = curA->next;
            } else if (!tailA) {
                tailA = curA;
                curA = headB;
            } else {
                break;
            }

            if (curB->next) {
                curB = curB->next;
            } else if (!tailB) {
                tailB = curB;
                curB = headA;
            } else {
                break;
            }
        }
        
        return begin;
    }
};
