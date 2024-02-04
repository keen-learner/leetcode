/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Iterative Solution
class Solution {
    public:
        bool isSymmetric(TreeNode* root){
            if(!root) return true;
            stack<TreeNode*> s;
            s.emplace(root->left);
            s.emplace(root->right);
            
            while(!s.empty()) {
                TreeNode* t1 = s.top();
                s.pop();
                TreeNode* t2 = s.top();
                s.pop();
                if (!t1 && !t2) continue;
                if (!t1 || !t2 || t1->val != t2->val) return false;
                s.emplace(t1->left);
                s.emplace(t2->right);
                s.emplace(t1->right);
                s.emplace(t2->left);
            }
            return true;
        }
};
// Recursive solution 
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return isSymmetricHelper(left->left, right->right) &&
               isSymmetricHelper(left->right, right->left);
    }
};
