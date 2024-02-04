/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode *curr = head;
        while(curr) {++n; curr= curr->next;}
        k = n-k+1;
        int cnt = 0;
        ListNode dummy{0};
        curr = &dummy;
        curr->next = head;
        ListNode *prev = NULL;
        while(cnt !=k ) {
            prev = curr;
            curr = curr->next;
            ++cnt;
        }
        prev->next = curr->next;
        delete curr;
        return dummy.next;
    }
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *slow = head, *fast = head, *pre = NULL;

            while(n > 0) {
                fast = fast->next;
                --n;
            }

            while(fast) {
                pre = slow;
                slow = slow->next;
                fast = fast->next;
            }

            if(!pre && !slow->next)
                return NULL;

            if(!pre && slow->next)
                return slow->next;

            pre->next = slow->next;
            delete slow;

            return head;        
    }
};
