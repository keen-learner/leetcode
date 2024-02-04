/*

Given a binary tree, find all leaves and then remove those leaves. 
Then repeat the previous steps until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Remove the leaves [4, 5, 3] from the tree

          1
         / 
        2          
2. Remove the leaf [2] from the tree

          1          
3. Remove the leaf [1] from the tree

          []         
Returns [4, 5, 3], [2], [1].

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

// Time:  O(n)
// Space: O(h)

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root, result); // calculates depth and updates result
        return result;
    }

private:
    int findLeavesHelper(TreeNode *node, vector<vector<int>>& result) { // leaf is 0
        if (node == NULL) return -1;

        const int level = 1 + max(findLeavesHelper(node->left, result),
                                  findLeavesHelper(node->right, result));

        //if (result.size() <= level){
        if (result.size() == level) { // means extend  
            result.push_back();
        }

        result[level].push_back(node->val);
        return level;
    }
};
