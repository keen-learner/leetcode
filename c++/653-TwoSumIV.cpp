/*

Given a Binary Search Tree and a target number, return true if there exist 
two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        int req = k - root->val;
        if(s.find(req) != s.end()) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> s;
};

class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root, res);
        int l = 0;
        int r = res.size()-1;
        while(l<r) {
            int curr = res[l] + res[r];
            if(curr == k) return true;
            else if(curr<k) ++l;
            else --r;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& res) {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
