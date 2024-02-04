/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = &dummy;
        while (curr->next && curr->next->next) {
            auto next_one = curr->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            curr->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            curr = next_one;
        }
        return dummy.next; 
    }
};

class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr = head;
        ListNode *curr2 = curr->next;
        ListNode *prev = NULL;
        while(1) {
            ListNode *temp = curr2->next;
            curr->next = temp;
            curr2->next = curr;
            if(!prev) head = curr2;
            else prev->next = curr2;
            prev = curr;
            curr = temp;
            if(!curr) break;
            curr2 = temp->next;
            if(!curr2) break;
        }
        return head;
    }
};
