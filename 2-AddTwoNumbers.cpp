/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8



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
        if (l1 == NULL) return l1;
        else if (l2 == NULL) return l2;
        else {
            ListNode *head = NULL; // head node of result List
            int carry = 0;
            ListNode *cur1 = l1;
            ListNode *cur2 = l2;
            ListNode *cur3;
            
            while (cur1 != NULL && cur2 != NULL) {
                if (head == NULL) {head = new ListNode(-1); cur3 = head;}
                else {cur3->next = new ListNode(-1); cur3 = cur3->next;}
                
                int res = cur1->val + cur2->val + carry;
                
                carry = res/10; cur3->val = res %10; cur3->next = NULL;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            
            if ((cur1 == NULL) && (cur2 != NULL)) {
                while (cur2 != NULL) {
                    int res = carry + cur2->val;
                    cur3->next = new ListNode(res%10);
                    carry = res/10; 
                    cur3 = cur3->next;
                    cur2 = cur2->next;
                }
                if (carry) cur3->next = new ListNode(1);cur3 = cur3->next; carry  = 0;
            }
            else if((cur2 == NULL) && (cur1 != NULL)){
                while (cur1 != NULL) {
                    int res = carry + cur1->val;
                    cur3->next = new ListNode(res%10);
                    carry = res/10;
                    cur3 = cur3->next;
                    cur1 = cur1->next;
                }
                if (carry) cur3->next = new ListNode(1);cur3 = cur3->next; carry  = 0;
            }
            else if ((cur1 == NULL) && (cur2 == NULL) && carry) {cur3->next = new ListNode(1);cur3 = cur3->next; carry  = 0;}
            return head;
        }
    }
};
// better codes, algo same 

// Time - O(n)
// Space - 0(1)
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2 || carry) {
            auto a = l1? l1->val : 0, b = l2? l2->val : 0;
            auto val = carry + a + b;
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }

        return dummy.next;
    }
};

#if 0
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* tail  = new ListNode(-1);
    ListNode* head  = tail;
    
    while(l1 || l2){
        int res = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        tail->next = new ListNode(res>9? res-10:res);  tail = tail->next;  carry = res>9? 1: 0;
        if(l1)l1=l1->next; if(l2)l2=l2->next;
    }
    if(carry) tail->next = new ListNode(1);
    
    return head->next;
#endif


// recursive solution

class Solution3 {
public:  
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(l1 == NULL) return l2;
      if(l2 == NULL) return l1;
      int sum = l1->val + l2->val;
      ListNode* l3;
      l3 = new ListNode(0);
      l3->next = addTwoNumbers(l1->next, l2->next); 
      if(sum <= 9) l3->val = sum;
      else {
          l3->val = sum - 10;
          ListNode* dummy;
          dummy = new ListNode(1);
          l3->next = addTwoNumbers(dummy, l3->next);
      }
      return l3;
  }
};

