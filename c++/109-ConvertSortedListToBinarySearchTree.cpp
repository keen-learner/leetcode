/*

Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        auto count = 0;
        auto *curr = head;
        while(curr) {
            ++count;
            curr = curr->next;
        }
        return helper(&head,count);
    }
 
private:
    TreeNode* helper(ListNode** head, int n) {
        if(n == 0) return NULL;
        auto m = n/2;
        auto left = helper(head, m);
        auto curr = new TreeNode((*head)->val);

        *head = (*head)->next;
        curr->left = left;
        curr->right = helper(head, n - m -1);
        return curr;
    }
};

class Solution1 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        auto count = 0;
        auto *curr = head;
        while(curr) {
            ++count;
            curr = curr->next;
        }
        return helper(&head, 0, count);
    }
 
private:
    TreeNode* helper(ListNode** head, int l, int h) {
        if(l == h) return NULL;
        auto m = l + (h-l)/2;
        auto left = helper(head, l, m);
        auto curr = new TreeNode((*head)->val);

        *head = (*head)->next;
        curr->left = left;
        curr->right = helper(head, m + 1, h);
        return curr;
    }
};
