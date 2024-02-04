/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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

// http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

// uses double pointer

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return helper(root, &prev);
    }
    bool helper(TreeNode* root, TreeNode** prev) {
        if (!root) return true;
        if (!helper(root->left, prev)) return false;
        if (*prev && (*prev)->val >= root->val) return false; //[1,1] gives false
        *prev = root;
        return helper(root->right, prev);
    }
};

// uses reference to a pointer, otherwise same as above
class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return helper(root, prev);
    }
    bool helper(TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        if (!helper(root->left, prev)) return false;
        if (prev && prev->val >= root->val) return false; //[1,1] gives false
        prev = root;
        return helper(root->right, prev);
    }
};

/*
This doesn't work, because if we have 1 node == INT_MAX
then it returns false, but should give true.
*/
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return helper(root, numeric_limits<long>::min(), numeric_limits<int>::max());        
    }
    
private:
    bool helper(TreeNode* root, int minb, int maxb) {
        if(!root) return true;
        if(root->val <= minb || root->val >= maxb) return false; //coz 1,1 shoould give false
        return helper(root->left, minb, root->val) &&
            helper(root->right, root->val, maxb);
    }
};

class Solution1 {
public:
    void inorder(TreeNode *root, vector<int> & res){
        if(root==NULL)
            return;
        inorder(root->left,res);    
        res.push_back(root->val);    
        inorder(root->right,res);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> res;
        inorder(root,res);
        for(int i=0;i<res.size()-1;i++)
            if(res[i]>=res[i+1])
                return false;
        return true;        
    }
};
