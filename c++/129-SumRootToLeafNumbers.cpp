/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res =0;
        int curr=0;
        helper(root, curr, res);
        return res;
    }
private:
    void helper(TreeNode* root, int cur, int& res) {
        // if(!root) {res += cur; return;} /*NOT NEEDED*/
        //if(!root) return;/* NOT NEEDED, guarantee 1 node  */
        if(!root->left && !root->right) {
            cur = cur*10 + root->val;
            res += cur;
            return;    
        }
        if(!root->left && root->right) {
            cur = cur*10 + root->val;
            helper(root->right, cur, res);
            return;
        }
        if(root->left && !root->right) {
            cur = cur*10 + root->val;
            helper(root->left, cur, res);
            return;
        }
        cur = cur*10 + root->val;
        helper(root->left, cur, res);
        helper(root->right, cur, res);
    }
};
