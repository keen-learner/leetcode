/*

Given a binary search tree (BST) with duplicates, find all the mode(s) (the 
most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that 
the implicit stack space incurred due to recursion does not count).

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

// need for two pass: case-> 1, 2, ..., n-1, n, n 
// res has [1, n-1] at a given point
class Solution {
public:
    TreeNode* prev = NULL;
    int cnt = 0;
    int maxfreq = 0;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        getMaxFreq(root); 
        cnt = 0; // NOTE: V IMP
        getModes(root);
        return res;
    }
    
    void getModes(TreeNode* root) {
        if(!root) return;
        getModes(root->left);
        if(prev && prev->val == root->val) ++cnt;
        else cnt = 1;
        if (cnt == maxfreq) {
            res.push_back(root->val);
        }
        prev = root;
        getModes(root->right);
    }    
    
    void getMaxFreq(TreeNode* root) {
        if(!root) return;
        getMaxFreq(root->left);
        if(prev && prev->val == root->val) ++cnt;
        else cnt = 1;
        
        if (cnt > maxfreq) {
            maxfreq = cnt;
        }
        prev = root;
        getMaxFreq(root->right);
    }
};

class Solution2 {
public:
    TreeNode* prev = NULL;
    int cnt = 0;
    int max = 0;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        helper(root); //do inorder traversal and update res
        return res;
    }
    
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        if(prev && prev->val == root->val) ++cnt;
        else cnt = 1;
        
        if (cnt > max) {
            res.clear();
            max = cnt;
            res.push_back(root->val);
        }
        else if (cnt == max) {
            res.push_back(root->val);
        }
        prev = root;
        helper(root->right);
    }
};

class Solution1 {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        int maxfreq = 0;
        unordered_map<int, int> m;
        helper(root, m, maxfreq); 
        vector<int> res;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second == maxfreq) res.push_back(it->first);
        }
        return res;
    }
    
    void helper(TreeNode* root, unordered_map<int, int>& m, int& maxfreq) {
        if(!root) return;
        helper(root->left, m, maxfreq);
        ++m[root->val];
        maxfreq = max(maxfreq, m[root->val]);
        helper(root->right, m, maxfreq);
    }
};
