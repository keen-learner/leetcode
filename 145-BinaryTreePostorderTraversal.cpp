/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
 
// Recursive solutions 
class Solution1 {
public:
    void postorder(TreeNode* root, vector<int>& res){
        if (root == NULL) return ;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        auto temp = postorderTraversal(root->left);
        res.insert(res.end(), temp.begin(), temp.end());
        temp = postorderTraversal(root->right);
        res.insert(res.end(), temp.begin(), temp.end());
        res.push_back(root->val);
        return res;
    }
};

// Iterative Solutions

// Morris Traversal
// Time:  O(n)
// Space: O(1)

class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(INT_MIN);
        dummy.left = root;
        auto *cur = &dummy;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                auto *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    const auto& v = trace_back(cur->left, node);
                    res.insert(res.end(), v.cbegin(), v.cend());
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }

private:
    vector<int> trace_back(const TreeNode *from, const TreeNode *to) {
        vector<int> res;
        auto *cur = from;
        while (cur != to) {
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        res.emplace_back(to->val);
        reverse(res.begin(), res.end());
        return res;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                s.emplace(root, true);
                s.emplace(root->right, false);
                s.emplace(root->left, false);
            }
        }
        return res;
    }
};
