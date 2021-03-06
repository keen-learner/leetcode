/*

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it 
must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the 
range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time : O(n^2)
// Space: O(h)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        unordered_map<int, int> m; //sum, count
        m[0] = 1;
        return helper (root, 0, sum, m);
    }

private:
    int helper(TreeNode* root, int curr, int& sum, unordered_map<int, int>& m) {
        if(!root) return 0;
        curr += root->val;

        int res = m.count(curr-sum) ? m[curr-sum] :0;
        m[curr]++;
        res += helper(root->left, curr, sum, m);
        res += helper(root->right, curr, sum, m);
        m[curr]--;
        if(m[curr] == 0) m.erase(curr);
        return res;
    }
};

// Time : O(n^2)
// Space: O(h)
class Solution2 {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        auto left = pathSum(root->left, sum);
        auto right = pathSum(root->right, sum);
        return left + right + helper (root, 0, sum);
    }

private:
    int helper(TreeNode* root, int currSum, int& sum) {
        if(!root) return 0;
        currSum += root->val;
        return (currSum == sum) + helper(root->left, currSum, sum) + helper(root->right, currSum, sum);
    }
};
