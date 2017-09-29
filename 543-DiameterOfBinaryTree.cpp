/*

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return depth(root)[0];
    }

private:
    vector<int> depth(TreeNode* root) { // return [max, depth]
        vector<int> res(2);
        if(!root) return {0, 0};
        auto l = depth(root->left);
        auto r = depth(root->right);
        res[0] = max(l[1]+r[1], max(l[0], r[0])); //max
        res[1] = 1 + max(l[1], r[1]); //depth
        return res;
    }
};

class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        depth(root, res);
        return res;
    }

private:
    int depth(TreeNode* root,int& res) {
        if(!root) return 0;
        int l = depth(root->left, res);
        int r = depth(root->right, res);
        res = max(res, l+r);
        return 1+ max( l, r);
    }
};

class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
       return max(depth(root->left)+ depth(root->right), 
                  max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

private:
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1+ max(depth(root->left), depth(root->right));
    }
};
