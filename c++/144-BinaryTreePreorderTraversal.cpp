/*

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
// recursive solution 1
class Solution1 {
public:
    void preorder(TreeNode* root, vector<int>& res){
        if (root == NULL) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};


// recursive solution 2
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.push_back(root->val);
        auto temp = preorderTraversal(root->left);
        res.insert(res.end(), temp.begin(), temp.end());
        temp = preorderTraversal(root->right);
        res.insert(res.end(), temp.begin(), temp.end());
        return res;
    }
};

// Itertaive Solutions

// solution using stack 
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        if(root == NULL) return res; 
        while(!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            res.push_back(n->val);
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
        }
        return res;
    }
};

// Morris Traversal
class Solution4 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        auto *curr = root;
        while (curr) {
            if (!curr->left) {
                res.emplace_back(curr->val);
                curr = curr->right;
            } else {
                auto *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    res.emplace_back(curr->val);
                    node->right = curr;
                    curr = curr->left;
                } else {
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                s.emplace(root->left, false);
                s.emplace(root, true);
            }
        }
        return res;
    }
};
