/*

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/


// Time:  O(n)
// Space: O(1)

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy{0};
        auto prev = &dummy;
        while (head) {
            if (head->next && head->next->val == head->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                prev->next = head;
            } 
            else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
