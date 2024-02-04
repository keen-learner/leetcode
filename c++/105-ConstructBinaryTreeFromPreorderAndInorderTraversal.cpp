/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        const int n = inorder.size();
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int k ; //index where root located in inorder
        for(k = is; inorder[k]!= preorder[ps] && k <= ie; k++);
        root->left = helper(preorder, inorder, ps+1, ps + k - is, is, k-1);
        root->right = helper(preorder, inorder, ps + k - is + 1, pe, k + 1, ie);
        return root;
    }
};


class Solution2 {
public:
  TreeNode *buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    return this->buildTree(0, 0, preorder.size(), preorder, inorder);
  }
private:
  TreeNode *buildTree(const size_t& i, const size_t& j, const size_t& n, const vector<int>& preorder, const vector<int>& inorder) {
    if (n == 0) return NULL;
    TreeNode *root = new TreeNode(preorder[i]);
    size_t k = j;
    for (k = j; k < j + n && inorder[k] != root->val; ++k);
    root->left = this->buildTree(i + 1, j, k - j, preorder, inorder);
    root->right = this->buildTree(i + k - j + 1, k + 1, n - k + j - 1, preorder, inorder);
    return root;
  }
};

// Time:  O(n)
// Space: O(n)

class Solution3 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            in_entry_idx_map.emplace(inorder[i], i);
        }
        return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size(),
                                            in_entry_idx_map);
    }

    // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
    // in[in_s : in_e - 1].
    TreeNode *ReconstructPreInOrdersHelper(const vector<int>& preorder, size_t pre_s, size_t pre_e,
                                           const vector<int>& inorder, size_t in_s, size_t in_e,
                                           const unordered_map<int, size_t>& in_entry_idx_map) {
        if (pre_s == pre_e || in_s == in_e) {
            return nullptr;
        }

        auto idx = in_entry_idx_map.at(preorder[pre_s]);
        auto left_tree_size = idx - in_s;

        auto node = new TreeNode(preorder[pre_s]);
        node->left = ReconstructPreInOrdersHelper(preorder, pre_s + 1, pre_s + 1 + left_tree_size,
                                                  inorder, in_s, idx, in_entry_idx_map);
        node->right = ReconstructPreInOrdersHelper(preorder, pre_s + 1 + left_tree_size, pre_e,
                                                   inorder, idx + 1, in_e, in_entry_idx_map);
        return node;
    }
};

// Iterative solution
class Solution4 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(preorder.size()==0)
            return NULL;
        
        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;
        
        f=i=j=0;
        s.push(preorder[i]);
        
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;
        
        while(i<preorder.size()) {
            if(!st.empty() && st.top()->val==inorder[j]) {
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else {
                if(f==0) {
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else {
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
        
        return root;
    }
};
