/*

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        root->next = NULL;
        while(root) { // this loop goes level by level, done till root, do for root's children and all those nodes at their level
            TreeLinkNode* curr = root;
            while(curr) { // this loop, actually doing this level, for curr and all curr->next
                if (curr->left) {
                    curr->left->next = curr->right?curr->right:getLeftMostFromNextLevel(curr);
                }
                if (curr->right) curr->right->next = getLeftMostFromNextLevel(curr);
                curr = curr->next;
            }
            if (root->left) root = root->left;
            else if (root->right) root = root->right;
            else root = getLeftMostFromNextLevel(root);
        }
    }
    
private:
    TreeLinkNode* getLeftMostFromNextLevel(TreeLinkNode* root) {
        root = root->next;
        while(root) {
            if(root->left) return root->left;
            if(root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }
};

class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        int n = 1;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) { 
            TreeLinkNode* temp = q.front();
            q.pop();
            if(n == 1) temp->next = NULL;
            else temp->next = q.front();
            --n;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(n == 0) { // level complete
                n = q.size();
            }
        }
    }
};
