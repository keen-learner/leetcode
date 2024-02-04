/*

Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For 
example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the 
path [1,2,4,3] is not valid. On the other hand, the path can be in the 
child-Parent-child order, where not necessarily be parent-child order.

Example 1:

Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
 

Example 2:

Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 

Note: All the values of tree nodes are in the range of [-1e7, 1e7].

*/


// Time:  O(n)
// Space: O(h)

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
    int longestConsecutive(TreeNode* root) {
        int max_len = 0;
        longestConsecutiveHelper(root, &max_len);
        return max_len;
    }

    pair<int, int> longestConsecutiveHelper(TreeNode *root, int *max_len) {
        if (!root) {
            return {0, 0};
        }
        const pair<int, int> left_len = longestConsecutiveHelper(root->left, max_len);
        const pair<int, int> right_len = longestConsecutiveHelper(root->right, max_len);

        int cur_inc_len = 1, cur_dec_len = 1;
        if (root->left) {
            if (root->left->val == root->val + 1) {
                cur_inc_len = max(cur_inc_len, left_len.first + 1);
            } else if (root->left->val == root->val - 1){
                cur_dec_len = max(cur_dec_len, left_len.second + 1);
            }
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                cur_inc_len = max(cur_inc_len, right_len.first + 1);
            } else if (root->right->val == root->val - 1) {
                cur_dec_len = max(cur_dec_len, right_len.second + 1);
            }
        }
        *max_len = max(*max_len, cur_dec_len + cur_inc_len - 1);
        return {cur_inc_len, cur_dec_len};
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, root, res);
        return res;
    }
    pair<int, int> helper(TreeNode* node, TreeNode* parent, int& res) {
        if (!node) return {0, 0};
        auto left = helper(node->left, node, res);
        auto right = helper(node->right, node, res);
        res = max(res, left.first + right.second + 1);
        res = max(res, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if (node->val == parent->val + 1) {
            inc = max(left.first, right.first) + 1;
        } else if (node->val + 1 == parent->val) {
            dec = max(left.second, right.second) + 1;
        }
        return {inc, dec};
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = helper(root, 1) + helper(root, -1) + 1;
        return max(res, max(longestConsecutive(root->left), longestConsecutive(root->right)));
    }
    int helper(TreeNode* node, int diff) {
        if (!node) return 0;
        int left = 0, right = 0;
        if (node->left && node->val - node->left->val == diff) {
            left = 1 + helper(node->left, diff);
        }
        if (node->right && node->val - node->right->val == diff) {
            right = 1 + helper(node->right, diff);
        }
        return max(left, right);
    }
};
