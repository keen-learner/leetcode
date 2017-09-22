/*

Given a binary tree, return all duplicate subtrees. For each kind of 
duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4


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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        unordered_map<string, vector<TreeNode*>> m;
        serialize(root, m);
        vector<TreeNode*> res;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second.size()>1) res.push_back(it->second[0]);
        }
        return res;
    }
private:    
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& m) {
        if(!root) return "";
        string res = to_string(root->val) + "," + serialize(root->left, m) + "," + serialize(root->right, m);
        m[res].push_back(root);
        return res;
    }
};
