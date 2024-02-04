/*

You are given two non-empty linked lists representing two non-negative 
integers. The most significant digit comes first and each of their nodes 
contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, 
reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int c = 0; // carry
        ListNode dummy(0);
        while(l1 || c || l2) {
            int a = l1?l1->val:0;
            int b = l2?l2->val:0;
            
            int sum = a+b+c;
            ListNode *temp = new ListNode(sum%10);
            c = sum/10;
            temp->next = dummy.next;
            dummy.next = temp;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return dummy.next;
    }
private:
    ListNode* reverse(ListNode* l1) {
        ListNode *prev = NULL;
        ListNode *curr = l1;
        while(curr) {
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }    
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode *curr = l1;
        while(curr) {
            s1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while(curr) {
            s2.push(curr->val);
            curr = curr->next;
        }
        int c = 0; // carry
        ListNode dummy(0);
        while(!s1.empty() || c || !s2.empty()) {
            int a, b;
            if(s1.empty()) { 
                a = 0;
            } else {
                a = s1.top();
                s1.pop();
            }
            if(s2.empty()) { 
                b = 0;
            } else {
                b = s2.top();
                s2.pop();
            }
            int sum = a+b+c;
            ListNode *temp = new ListNode(sum%10);
            c = sum/10;
            temp->next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;
    }
};
