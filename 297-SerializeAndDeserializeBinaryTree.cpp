/*

http://www.geeksforgeeks.org/serialize-deserialize-binary-tree/


Serialization is the process of converting a data structure or object into 
a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed 
later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is 
no restriction on how your serialization/deserialization algorithm should 
work. You just need to ensure that a binary tree can be serialized to a 
string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a 
binary tree. You do not necessarily need to follow this format, so please 
be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.

*/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { //preorder
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return helper(data, i);     
    }
   
private:    
    TreeNode* helper(string& data, int& i) { // deserialize starting from index i
        // if(i >= data.size() || data[i] == '#' || data == "") {
        if(i >= data.size() || data[i] == '#') { //don't need data==""
            i+=2;
            return NULL;
        }
        int j = i;
        // for(; i< data.size(); i++) {
        //     if(data[i] == ',') break;
        // }
        // instead of loop, use find(string/char, pos) - finds string/char in [pos,size()-1]
        i = data.find(',', j);
        string sval = data.substr(j, i-1 - j + 1); // [0,j-1] substring
        //cout<<sval<<endl;
        int val = stoi(sval);
        TreeNode* root = new TreeNode(val);
        i++;
        root->left = helper(data, i);
        root->right = helper(data, i);
        return root;
    }
};
