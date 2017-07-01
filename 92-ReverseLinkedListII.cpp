/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n) return head;
        
        ListNode* prev =  NULL;
        ListNode* curr =  head;
        int count = 1;
        while(count != m) {
            prev = curr;
            curr =  curr->next;
            ++count;
        }
        
        ListNode* prev2 = prev; // (m-1)th node
        ListNode* curr2 = curr; // mth node
        
        while(count != n) {
            prev2 = curr2;
            curr2 = curr2->next;
            ++count;
        }
        prev2 = curr2;
        curr2 = curr2->next;
        
        ListNode* tprev = NULL;
        ListNode* tcurr = curr;
        while(tcurr != curr2) {
            ListNode* temp = tcurr->next;
            tcurr->next = tprev;
            tprev = tcurr;
            tcurr = temp;
        }
        if(!prev) { // m =1;
            curr->next = curr2;
            return tprev; //return nth node   
        }
        else {
            prev->next = tprev;
            curr->next = curr2;
            return head;
        }
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n) return head;
        ListNode* prev =  NULL;
        ListNode* curr =  head;
        int count = 1;
        while(count != m) {
            prev = curr;
            curr =  curr->next;
            ++count;
        }
        ListNode* temp = prev; // (m-1)th node
        ListNode* temp2 = curr; // mth node
        // reverse from m to n
        while(count != n) {
            ListNode* t = curr->next;
            curr->next = prev;
            ++count;
            prev = curr;
            curr = t;
        }
        // temp has m-1; temp2 has m; curr has nth
        temp2->next = curr->next; // m point to n+1
        curr->next = prev; // n point to n-1
        if (!temp) return curr; // if m=1 return n as head
        temp->next = curr; // m-1 point to n
        return head; // head is same
    }
};
