/*

Given a non-negative number represented as a singly 
linked list of digits, plus one to the number.

The digits are stored such that the most significant 
digit is at the head of the list.

Example:
Input:
1-> 2-> 3

Output:
1-> 2-> 4

*/

class Solution {
public:
  ListNode* plusOne(ListNode* head) {
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    for (ListNode * it = dummy; it; it = it->next) {
      if (it->val != 9) {
        head = it;
      }
    }
    ++(head->val);
    head = head->next;
    while (head) {
      head->val = 0;
      head = head->next;
    }
    return dummy->val ? dummy : dummy->next;
  }
};

class Solution2 {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        int carry = helper(head);
        if (carry == 1) {
            ListNode *res = new ListNode(1);
            res->next = head;
            return res;
        }
        return head;
    }
    int helper(ListNode *node) {
        if (!node) return 1;
        int carry = helper(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};

class Solution1 {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
        int carry = 1;
        while (cur) {
            pre = cur;
            int t = cur->val + carry;
            cur->val = t % 10;
            carry = t / 10;
            if (carry == 0) break;
            cur = cur->next;
        }
        if (carry) pre->next = new ListNode(1);
        return reverse(rev_head);
    }
    ListNode* reverse(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};
