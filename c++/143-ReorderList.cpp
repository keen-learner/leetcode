/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // if(!head) return; gives error
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {    
            slow = slow->next;
            fast = fast->next->next;
        }
        // fast!=NULL for odd, fast == NULL for even
        ListNode* head2 = reverse(fast?slow->next:slow);
        ListNode* curr = head;
        ListNode* curr2 = head2;
        
        while(curr2) {
            ListNode* t = curr->next;
            ListNode* t2 = curr2->next;
            curr->next = curr2;
            curr2->next = t;
            curr = t;
            curr2 = t2;
        }
        curr->next = NULL;
    }
    
private:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
    
};

class Solution1 {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // if(!head) return; gives error
        ListNode* slow = head;
        ListNode* fast = head;
        //while(fast->next && fast->next->next) {
        while(fast && fast->next) {    
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverse(fast?slow->next:slow);
        ListNode* curr = head;
        ListNode* curr2 = head2;
        
        while(1) {
            ListNode* t = curr->next;
            ListNode* t2 = curr2->next;
            curr->next = curr2;
            curr2->next = t;
            curr = t;
            curr2 = t2;
            if(!curr2) {curr->next = NULL; return;}
            if(!curr->next && !curr2->next) {
                // Following statement not needed
                // curr->next = curr2; 
                return;
            }
        }
        
        //return ;
    }
private:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
    
};
