/*

One way to serialize a binary tree is to use pre-order traversal. When 
we encounter a non-null node, we record the node's value. If it is a 
null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string 
"9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct 
preorder traversal serialization of a binary tree. Find an algorithm 
without reconstructing the tree.

Each comma separated value in the string must be either an integer or a 
character '#' representing null pointer.

You may assume that the input format is always valid, for example it could 
never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string s;
        int degree = -1; //root gets negative
        while(getline(ss, s, ',')) {
            degree++; // incoming edge
            if(degree>0) return false;
            if(s!="#") degree -= 2;
        }
        return degree==0;
    }
};

class Solution2 {
public:
    bool isValidSerialization(string preorder) {
        int bal = 0;
        stringstream ss(preorder);
        string val;
        while(getline(ss,val,',')){
            bal += val == "#" ? -1 : 1;
            /*
                balance should go negative only at the end because non null
                added before null. 
                Hence after break we check if it's the end
            */
            if (bal < 0) break; 
        }
        string check;
        return bal == -1 && !(bool)getline(ss,check,',');
    }
};

class Solution1 {
public:
    bool isValidSerialization(string preorder) {
         vector<string> stk;
         preorder+=",";
         stringstream is(preorder);
         string token;
         while(getline(is,token,',')) {
             if(token=="#") {
                while(!stk.empty() && stk.back()=="#") {
                    stk.pop_back();
                    if(stk.empty()) return false;
                    stk.pop_back();
                }
             }
             stk.push_back(token);  
         }
         if(stk.size()==1 && stk[0]=="#") return true;
         return false;
    }
};
