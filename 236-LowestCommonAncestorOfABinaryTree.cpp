// http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
         // 1. If the current subtree contains both p and q,
         //    return their LCA.
         // 2. If only one of them is in that subtree,
         //    return that one of them.
         // 3. If neither of them is in that subtree,
         //    return the node of that subtree.
        return left ? (right ? root : left) : right;
    }
};

// Find LCA, given parent pointer
// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-2-using-parent-pointer/

//     9
 //   4  7
 //  1 2   5
 // 8
  
 // Given 2 nodes, find LCA (lowest common ancestor)
 // 8, 5 ====> 9
 // 8, 2 ====> 4
 
 struct Node {
     int key;
     Node* parent;
 }
 
 Node* LCA (Node* a, Node* b) {
    set<Node*> ancestors;
    
    while(a) {
        ancestors.insert(a);
        a = a->parent;
    }
    
    while (b) {
        if (ancestors.find(b) != ancestors.end()) {
            return b;
        }
        b = b->parent;
    }
    return NULL;

 }
 
 int depth (Node* root) {
     int d = -1;
     while (root) {
         ++d;
         root = root->parent;
     }
     return d;
 }
 
 Node* LCA2 (Node* a, Node* b) {
     int da = depth(a);
     int db = depth(b);
     
     int diff;
     if (da > db) {
         diff = da - db;
     } else {
         diff = db - da;
         swap(a, b);
     }
     
     // a is the deeper node
     while (diff) {
         a = a->parent;
     }
     
     // both nodes at same level
     while (a && b) {
         if (a == b) {
             return a;
         }
         a = a->parent;
         b = b->parent;
     }
     return NULL;
 }
