/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
 
// Recursive Solution 
class Solution1 {
public:
    void inorder(TreeNode *root, vector<int>& res){
        if(root==NULL)
            return;
        inorder(root->left,res);    
        res.push_back(root->val);
        inorder(root->right,res);        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};


// Time:  O(n)
// Space: O(1)

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                res.emplace_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    res.emplace_back(curr->val);
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
            tie(root, visited) = s.top();
            s.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                s.emplace(root->right, false);
                s.emplace(root, true);
                s.emplace(root->left, false);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));
        //s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
            // tie(root, visited) = s.top();
            auto t = s.top();
            s.pop();
            if (t.first == nullptr) { //null node
                continue;
            }
            if (t.second) { // node already visited
                res.emplace_back(t.first->val);
            } else {
                s.emplace(t.first->right, false);
                s.emplace(t.first, true);
                s.emplace(t.first->left, false);
            }
        }
        return res;
    }
};
