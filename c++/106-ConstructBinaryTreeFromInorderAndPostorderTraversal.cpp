/*

Given inorder and postorder traversal of a tree, construct the binary tree.

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

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return NULL;
        const int n = inorder.size();
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ps, int pe, int is, int ie) {
        if (ps > pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int k ; //index where root located in inorder
        for(k = is; inorder[k]!= postorder[pe] && k <= ie; k++);
        root->left = helper(inorder, postorder, ps, ps + k - is -1, is, k-1);
        root->right = helper(inorder, postorder, ps + k - is, pe-1, k + 1, ie);
        return root;
    }
};


// Iterative O(n) solution

/*

Only nodes whoes left side hasn't been handled will be pushed into stn.

And inorder is organized as (inorder of left) root (inorder of right),

And postorder is as (postorder of left) (postorder of right) root.

So at the very begin, we only have root in stn and we check if inorder.back() == root->val and in most cases it's false(see Note 1). Then we make this node root's right sub-node and push it into stn.

Note 1: this is actually (inorder of right).back() == (postorder of right).back(), so if only there's no right subtree or the answer will always be false.

Note 2: we delete one node from postorder as we push one into stn.

Now we have [root, root's right] as stn and we check inorder.back() == stn.top()->val again.

true means inorder.back() is the root node and needs handled left case.
false means inorder.back() is the next right sub-node
So when we encounter a true, we will cache stn.top() as p and delete both nodes from inorder and stn.

Then we check inorder.size(), if there's no nodes left, it means p has no left node.

Else the next node in inorder could be p's left node or p's father which equals to the now stn.top() (remember we popped p from stn above).

If the latter happens, it means p has no left node and we need to move on to p's father(stn.top()).

If the former happens, it means p has one left node and it's postorder.back(), so we put it to p's left and delete it from the postorder and push the left node into stn 'cause it should be the next check node as the postorder is organized as above.

That's all of it. The algs just build a binary tree. :)

Inform me if there's anything vague or wrong, I'm open to any suggestions.

*/


class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;
        
        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 
        
        while(true) {
            if(inorder.back() == stn.top()->val) {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};
