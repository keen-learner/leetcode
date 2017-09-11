/*

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If 
there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves 
are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        root->next = NULL;
        while(root) { // this loop goes level by level, done till root, do for root's children and all those nodes at their level
            TreeLinkNode* curr = root;
            while(curr) { // this loop, actually doing this level, for curr and all curr->next
                // if checks needed, for case of single node
                if (curr->left) {
                    curr->left->next = curr->right;
                }
                if (curr->right) {
                    curr->right->next = curr->next?curr->next->left:NULL;
                }
                curr = curr->next;
            }
            root = root->left;
        }
    }
};

// same as 117. Populating Next Right Pointers in Each Node II
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        root->next = NULL;
        while(root) { // this loop goes level by level, done till root, do for root's children and all those nodes at their level
            TreeLinkNode* curr = root;
            while(curr) { // this loop, actually doing this level, for curr and all curr->next
                if (curr->left) {
                    curr->left->next = curr->right?curr->right:getLeftMostFromNextLevel(curr);
                }
                if (curr->right) curr->right->next = getLeftMostFromNextLevel(curr);
                curr = curr->next;
            }
            if (root->left) root = root->left;
            else if (root->right) root = root->right;
            else root = getLeftMostFromNextLevel(root);
        }
    }
    
private:
    TreeLinkNode* getLeftMostFromNextLevel(TreeLinkNode* root) {
        root = root->next;
        while(root) {
            if(root->left) return root->left;
            if(root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }
};
