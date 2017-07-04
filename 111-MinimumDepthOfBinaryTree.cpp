/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

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

// http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/ 
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        /*
        Need the following 2 cases, coz if 1 is null, that side will return min always(=0)
        This is not we want.
        example:   1
                 2     should return 2
        */
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return (min(minDepth(root->left), minDepth(root->right)) + 1);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        int minDepth(TreeNode *root) {
            if(!root)
                return 0;

            queue<TreeNode *> q;
            int d = 1;
            q.push(root);
            int cnt = q.size();

            // BFS or Level Order Traversal
            while(!q.empty()) {
                TreeNode *n = q.front();
                q.pop();

                if(!n->left && !n->right)
                    return d;
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);

                cnt--;
                if(!cnt) {
                    cnt = q.size();
                    d++;
                }
            }
        }
};
