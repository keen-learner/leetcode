/*

Given a non-empty binary search tree and a target value, find k values in the 
BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the 
BST that are closest to the target.
 

Follow up:
Assume that the BST is balanced, could you solve it in less 
than O(n) runtime (where n = total nodes)?

Hint:

1. Consider implement these two helper functions:
　　i. getPredecessor(N), which returns the next smaller node to N.
　　ii. getSuccessor(N), which returns the next larger node to N.
2. Try to assume that each node has a parent pointer, it makes the problem much easier.
3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
4. You would need two stacks to track the path in finding predecessor and successor node separately.

*/

// 2 stacks solution
// http://www.cnblogs.com/grandyang/p/5247398.html
// https://discuss.leetcode.com/topic/30597/java-5ms-iterative-following-hint-o-klogn-time-and-space/4

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pre, suc;
        while (root) {
            if (root->val <= target) {
                pre.push(root);
                root = root->right;
            } else {
                suc.push(root);
                root = root->left;
            }
        }
        while (k-- > 0) {
            if (suc.empty() || !pre.empty() && target - pre.top()->val < suc.top()->val - target) {
                res.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                res.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        return res;
    }
    void getPredecessor(stack<TreeNode*> &pre) {
        TreeNode *t = pre.top(); pre.pop();
        if (t->left) {
            pre.push(t->left);
            while (pre.top()->right) pre.push(pre.top()->right);
        }
    }
    void getSuccessor(stack<TreeNode*> &suc) {
        TreeNode *t = suc.top(); suc.pop();
        if (t->right) {
            suc.push(t->right);
            while (suc.top()->left) suc.push(suc.top()->left);
        }
    }
};



//priority queue
class Solution3 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>> q; // max priority queue
        inorder(root, target, k, q);
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop ();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        q.push({abs(root->val - target), root->val});
        if (q.size() > k) q.pop();
        inorder(root->right, target, k, q);
    }
};

// modifed inorder traversal 
class Solution2 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        if (res.size() < k) res.push_back(root->val);
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } 
        else  return ;
        inorder(root->right, target, k, res);
    }
};

// store inorder traversal in an array and then find k values
class Solution1 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res, v;
        inorder(root, v);
        int idx = 0;
        double diff = numeric_limits<double>::max();
        for (int i = 0; i < v.size(); ++i) {
            if (diff >= abs(target - v[i])) {
                diff = abs(target - v[i]);
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[idx]);
            if (left >= 0 && right < v.size()) {
                if (abs(v[left] - target) > abs(v[right] - target)) {
                    idx = right;
                    ++right;
                } 
                else {
                    idx = left;
                    --left;
                }
            } 
            else if (left >= 0) {
                idx = left;
                --left;
            } 
            else if (right < v.size()) {
                idx = right;
                ++right;
            }
        }
        return res;
    }
    void inorder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

