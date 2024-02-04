/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode small{0};
        ListNode large{0};
        auto curr_small = &small;
        auto curr_large = &large;
        
        while(head) {
            if(head->val < x) {
                curr_small->next = head;
                curr_small = curr_small->next;
            }
            else {
                curr_large->next = head;
                curr_large = curr_large->next;
            }
            head = head->next;
        }
        curr_small->next = large.next;
        curr_large->next = NULL;
        return small.next;
        
    }
};
