/*

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child 
points to the next node of a pre-order traversal.

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
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left && root->right) {
                TreeNode* t = root->left;
                while (t->right) t = t->right;
                t->right = root->right;
            }
            if(root->left) root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};

class Solution1 {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        return helper(root, &prev);
    }
    void helper(TreeNode* root, TreeNode** prev) {
        if(!root) return;
        helper(root->right, prev);
        helper(root->left, prev);
        root->right = *prev;
        root->left = NULL;
        *prev = root;
    }
};
