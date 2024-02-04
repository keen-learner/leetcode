/*

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* curr = head;
        while(curr->next != NULL){
            if (curr->next->val == val) { // delete curr->next
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else curr =  curr->next;
        }
        if(head->val == val) {
            ListNode* t = head;
            head = t->next;
            delete t;
        }
        return head;
    }
};
 
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next != NULL){
            if (curr->next->val == val) { // delete curr->next
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else curr =  curr->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
