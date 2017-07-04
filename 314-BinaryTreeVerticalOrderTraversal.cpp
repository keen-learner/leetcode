/*

Given a binary tree, return the vertical order traversal of its nodes' 
values. (Ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples: 
Given binary tree [3,9,20,null,null,15,7]

  3
    / \
   9 20
     / \
    15 7
Return its vertical order traversal as:

  [
   [9],
   [3,15],
   [20],
   [7]
 ]
Given binary tree [3,9,20,4,5,2,7] ,

  _3_
    / \
   9 20
  / \ / \
 4 5 2 7
Return its vertical order traversal as:

  [
   [4],
   [9],
   [3,5,2],
   [20],
   [7]
 ] 

*/

class Solution1 {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        vector<pair<TreeNode *, int>> queue{{root, 0}};
        for (int i = 0; i < queue.size(); ++i) {
            TreeNode *node;
            int j;
            tie(node, j) = queue[i];
            if (node) {
                cols[j].emplace_back(node->val);
                queue.push_back({node->left, j - 1});
                queue.push_back({node->right, j + 1});
            }
        }
        int min_idx = numeric_limits<int>::max(), 
            max_idx = numeric_limits<int>::min();
        for (const auto& kvp : cols) {
            min_idx = min(min_idx, kvp.first);
            max_idx = max(max_idx, kvp.first);
        }
        vector<vector<int>> res;
        for (int i = min_idx; !cols.empty() && i <= max_idx; ++i) {
            res.emplace_back(move(cols[i]));
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        vector<vector<int>> res;
        map<int, vector<int>> cols;
        while(!q.empty()) {
            tie(TreeNode* f, id) = q.front();
            q.pop();
            cols[id].push_back(f->val);
            if(f->left) q.push(make_pair(f->left, id-1));
            if(f->right) q.push(make_pair(f->right, id+1));
        }
        
        for(auto it = cols.begin(); it != cols.end(); ++it) res.push_back(it->second);
        return res;
    }
};
