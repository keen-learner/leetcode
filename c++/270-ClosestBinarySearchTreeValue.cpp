/*


Given a non-empty binary search tree and a target value, find the 
value in the BST that is closest to the target

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST 
that is closest to the target.

*/

class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    if (!root) {
      return INT_MIN;
    }
    int result = root->val;
    while (root) {
      if (abs(root->val - target) < abs(result - target)) {
        result = root->val;
      }
      if (root->val == target) {
        return result;
      }
      if (root->val < target) {
        root = root->right;
      }
      else {
      root = root->left;
      }
    }
    return result;
  }
};

class Solution1 {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (target < root->val && root->left) {
            int l = closestValue(root->left, target);
            if (abs(res - target) >= abs(l - target)) res = l;
        } 
        else if (target > root->val && root->right) {
            int r = closestValue(root->right, target);
            if (abs(res - target) >= abs(r - target)) res = r;
        }
        return res;
    }
};
