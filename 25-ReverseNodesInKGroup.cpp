/*

Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list.

k is a positive integer and is less than or equal to the length of the 
linked list. If the number of nodes is not a multiple of k then 
left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node=head;
        for (int i=0; i < k; ++i) {
            if (!node ) return head; // nothing to do list too sort
            node = node->next;
        }

        ListNode* new_head = reverse(head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }
    
    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode* prev = last; // NOTE: V. IMP
        while ( first != last ) {
            ListNode* tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        } 
        return prev;
    }
};


class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* curr = head; 
        ListNode* curr_dummy = &dummy;
        int len = 0;

        while (curr) {
            ListNode* next_curr = curr->next;
            len = (len + 1) % k;

            if (len == 0) {
                ListNode* next_dummy = curr_dummy->next;
                reverse(&curr_dummy, next_curr);
                curr_dummy = next_dummy;
            }
            curr = next_curr;
        }
        return dummy.next;
    }

    void reverse(ListNode **begin, const ListNode *end) {
        ListNode *first = (*begin)->next;
        ListNode *curr = first->next;

        while (curr != end) {
            first->next = curr->next;
            curr->next = (*begin)->next;
            (*begin)->next = curr;
            curr = first->next;
        }
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* curr = head; 
        ListNode* prev = &dummy; //till prev, list is k group reversed 
        int len = 0;

        while (curr) {
            for(int i = 0; i<k; i++) {
                if(!curr) return dummy.next; // k nodes not present
                curr = curr->next;
            }
            ListNode* t = reverse(prev->next, curr);
            ListNode* new_prev = prev->next;
            prev->next = t;
            prev = new_prev;
        }
        return dummy.next;
    }

    ListNode* reverse(ListNode *head, ListNode *end) {
        ListNode *prev = end;
        ListNode *curr = head;

        while (curr != end) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
